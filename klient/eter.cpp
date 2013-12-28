#include "eter.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>

Ether::Ether(QObject *parent) :
    QObject(parent), fieldsAreCreated(false)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceTime()));
}

void Ether::start(int timeDelay)
{
    _timeDelay = timeDelay;
    timer->start(_timeDelay);
}

std::vector<Field> Ether::getFields()
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
            fields.push_back(Field(sector_size_x, sector_size_y, i, j));
    fieldsAreCreated=true;
}

void Ether::registerRobotInEther(int32_t local_id,
                                 int32_t id,
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
    _allRobotsOnScene.push_back(newRobot);
    emit addRobotToSceneSignal(id, 0, 0);
    //    newRobot pNewRobot(newRobot(local_id, id, size_x, size_y));/* = new Robot(local_id, id, size_x, size_y);*/
    //    _allRobotsOnScene.push_back(newRobot);
    // uh jeszcze trzeba ogarnąć tę ewentualną zmicd anę wielkosci pola
}

void Ether::setRobotNextField(int32_t id, int32_t nextFieldX, int32_t nextFieldY)
{
    BOOST_FOREACH(Field &field, fields){
        if(field.setRobotNextField(id, nextFieldX, nextFieldY))
            return;
    }
}
