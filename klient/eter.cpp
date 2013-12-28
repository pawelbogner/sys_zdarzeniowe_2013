#include "eter.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>

Ether::Ether(QObject *parent) :
    QObject(parent)
{

}

void Ether::start()
{

}

void Ether::advanceTime()
{

}

void Ether::registerRobotInEther(int32_t local_id,
                                 int32_t id,
                                 int32_t sector_size_x,
                                 int32_t sector_size_y,
                                 int32_t size_x,
                                 int32_t size_y)
{
    boost::shared_ptr<Robot> newRobot = boost::make_shared<Robot>(local_id, id, size_x, size_x);
    _allRobotsOnScene.push_back(newRobot);

    //    newRobot pNewRobot(newRobot(local_id, id, size_x, size_y));/* = new Robot(local_id, id, size_x, size_y);*/
    //    _allRobotsOnScene.push_back(newRobot);
    // uh jeszcze trzeba ogarnąć tę ewentualną zmicd anę wielkosci pola
}

void Ether::setRobotNextField(int32_t id, int32_t nextFieldX, int32_t nextFieldY)
{
    BOOST_FOREACH(Field field, fields){
        if(field.setRobotNextField(id, nextFieldX, nextFieldY))
            return;
    }
}
