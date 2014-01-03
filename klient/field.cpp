#include "field.h"
#include "qprotocol.h"
#include <boost/foreach.hpp>
#include"eter.h"


Field::Field(int32_t xSize, int32_t ySize, int32_t xCoord, int32_t yCoord, Ether *ourEther):
    _xSize(xSize), _ySize(ySize), _xCoord(xCoord), _yCoord(yCoord), _ourEther(ourEther)
{ }

void Field::removeRobot(boost::shared_ptr<Robot> robot)
{
   std::vector<boost::shared_ptr<Robot> >::iterator it;
   for(it=_robotsOnField.begin(); it!=_robotsOnField.end(); ++it)
       if((*it).get() == robot.get()){
           _robotsOnField.erase(it);
           break;
       }
}

void Field::addRobot(boost::shared_ptr<Robot> robot)
{
    _robotsOnField.push_back(robot);
}

void Field::reallocateRobot(boost::shared_ptr<Robot> robot)
{
    removeRobot(robot);
    Field *nextField=_ourEther->findFieldWithCoords(_xCoord+robot->getNextFieldXPos(),
                                                    _yCoord+robot->getNextFieldYPos());
    if (nextField!=NULL) {
        nextField->addRobot(robot);
        robot->setPrevFieldXPos(_xCoord);
        robot->setPrevFieldYPos(_yCoord);
        robot->setXPos(robot->getXPos()-xSize()*robot->getNextFieldXPos());
        robot->setYPos(robot->getYPos()-ySize()*robot->getNextFieldYPos());
    }
    else {
        std::cerr << "Error: robot appears to have gone out of scene bounds. Rofl." << std::endl;
    }
}

void Field::computeOneIterationOfMotion(int timeDelay)
{
    if(_robotsOnField.size() == 1)
    {
        _robotsOnField[0]->calculatePosition(_xSize, _ySize, boost::shared_ptr<Robot>(), timeDelay);
    }
    else if(_robotsOnField.size() == 2)
    {
        _robotsOnField[0]->calculatePosition(_xSize, _ySize, _robotsOnField[1], timeDelay);
        _robotsOnField[1]->calculatePosition(_xSize, _ySize, _robotsOnField[0], timeDelay);
    }
    BOOST_FOREACH(boost::shared_ptr<Robot> robot, _robotsOnField){
        //std::cout << "robot position: " << robot->getXPos() << " " << robot->getYPos() << std::endl;
        if (robot->getXPos()<0.0 || robot->getXPos()>_xSize || robot->getYPos()<0.0 || robot->getYPos()>_ySize) {
            reallocateRobot(robot);
            robot->setPrevFieldReleased(false);
            robot->setNextFieldXPos(0);
            robot->setNextFieldYPos(0);
            robot->setIsAllowedToLeaveField(false);
        }
        if ((robot->getXPos()>DIAMETER/2 && robot->getXPos()<_xSize-DIAMETER/2) &&
                (robot->getYPos()>DIAMETER/2 && robot->getYPos()<_ySize-DIAMETER/2)) { // robot zajmuje tylko 1 pole
            if(!robot->getPrevFieldReleased()) {
                _ourEther->client()->request_sector(robot->getGlobalId(), robot->getPrevFieldXPos(),
                                                    robot->getPrevFieldYPos(), eRelease);
                robot->setPrevFieldReleased(true);
            }
        }
    }
}

boost::shared_ptr<Robot> Field::getRobotWithMatchingId(int32_t id)
{
    BOOST_FOREACH(boost::shared_ptr<Robot> robot, _robotsOnField){
        //tu bedziemy szukac robota maczujacego po id
        if(robot->getGlobalId() == id)
            return robot;
    }
    return boost::shared_ptr<Robot>();
}

bool Field::setRobotNextField(int32_t globalId, int32_t nextFieldX, int32_t nextFieldY)
{
    boost::shared_ptr<Robot> currentRobot = getRobotWithMatchingId(globalId);
    if(currentRobot.get())
    {
        currentRobot->setNextFieldXPos(nextFieldX-_xCoord);
        currentRobot->setNextFieldYPos(nextFieldY-_yCoord);
        return true;
    }
    return false;
}

std::vector<boost::shared_ptr<Robot> > &Field::getRobotsOnField()
{
    return _robotsOnField;
}
int32_t Field::xSize() const
{
    return _xSize;
}

int32_t Field::ySize() const
{
    return _ySize;
}
int32_t Field::xCoord() const
{
    return _xCoord;
}

int32_t Field::yCoord() const
{
    return _yCoord;
}
