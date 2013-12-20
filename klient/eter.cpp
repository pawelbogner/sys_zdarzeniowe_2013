#include "eter.h"

#include <boost/shared_ptr.hpp>

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

void Ether::registerRobotInEter(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y)
{
    boost::shared_ptr<Robot> newRobot;

    //    newRobot pNewRobot(newRobot(local_id, id, size_x, size_y));/* = new Robot(local_id, id, size_x, size_y);*/
    //    _allRobotsOnScene.push_back(newRobot);
    // uh jeszcze trzeba ogarnąć tę ewentualną zmianę wielkosci pola
}
