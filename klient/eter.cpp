#include "eter.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>

Ether::Ether(QClient *client, QObject *parent) :
    QObject(parent), fieldsAreCreated(false), _client(client)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceTime()));
}

void Ether::start(int timeDelay)
{
    _timeDelay = timeDelay;
    timer->start(_timeDelay);
}

std::vector<Field> &Ether::getFields()
{
    return fields;
}

void Ether::advanceTime()
{
    timer->stop();
    for(std::vector<Field>::iterator it=fields.begin();it!=fields.end();it++)
    {
        (*it).computeOneIterationOfMotion(_timeDelay);
    }
    timer->start(_timeDelay);
    emit redrawScene();
}

void Ether::createFields(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y)
{
    for(int i=0; i<size_x; ++i)
        for(int j=0; j<size_y; ++j)
            fields.push_back(Field(sector_size_x, sector_size_y, i, j, this));
    fieldsAreCreated=true;
}

void Ether::registerRobotInEther(int32_t local_id,
                                 int32_t id,
                                 int32_t startingX,
                                 int32_t startingY,
                                 int32_t sector_size_x,
                                 int32_t sector_size_y,
                                 int32_t size_x,
                                 int32_t size_y)
{
    if(!fieldsAreCreated){
        createFields(size_x, size_y, sector_size_x, sector_size_y);
        emit drawSceneWithLines(size_x, size_y, sector_size_x, sector_size_y);
    }
    boost::shared_ptr<Robot> newRobot = boost::make_shared<Robot>(local_id, id);
    newRobot->setXPos(DIAMETER);
    newRobot->setYPos(DIAMETER);
    _allRobotsOnScene.push_back(newRobot);
    if (startingX>size_x-1) {
        startingX=0;
    }
    if (startingY>size_y-1) {
        startingY=0;
    }
    getFields().at(startingY+startingX*size_y).addRobot(getRobotWithMatchingId(id));
    _client->current_position(id,startingX,startingY);
    emit addRobotToSceneSignal(id);
}

void Ether::setRobotNextField(int32_t id, int32_t nextFieldX, int32_t nextFieldY)
{
    BOOST_FOREACH(Field &field, fields){
        if(field.setRobotNextField(id, nextFieldX, nextFieldY)) {
            _client->request_sector(id, nextFieldX, nextFieldY, eReserve);
            emit goToEtherSignal(id,nextFieldX,nextFieldY);
            return;
        }
    }
}

boost::shared_ptr<Robot> Ether::getRobotWithMatchingId(int32_t id)
{
    BOOST_FOREACH(boost::shared_ptr<Robot> robot, _allRobotsOnScene){
        //tu bedziemy szukac robota maczujacego po id
        if(robot->getGlobalId() == id)
            return robot;
    }
    return boost::shared_ptr<Robot>();
}

Field *Ether::findFieldWithCoords(int32_t x, int32_t y) {
    BOOST_FOREACH(Field &field, fields){
        if (field.xCoord()==x && field.yCoord()==y){
            return &field;
        }
    }
    return NULL;
}

QClient *Ether::client() const
{
    return _client;
}

