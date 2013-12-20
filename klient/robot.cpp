#include "robot.h"

//Robot::Robot(int32_t diameter, int32_t id):
//    _diameter(diameter), _localId(id), _globalId(0), _isAllowedToLeaveField(false)
//{ }

Robot::Robot(int32_t local_id, int32_t id, int32_t size_x, int32_t size_y):
    _localId(local_id), _diameter(size_x), _globalId(id), _isAllowedToLeaveField(false)
{

}

Force Robot::calculateForce()
{
    // na podstawie następujących danych:
    // - szerokość w X i w Y pojedynczego pola,
    // - diameter robota,
    // - _isAllowedToLeaveField,
    // - współrzędnych pola, na które ma wyjechać,
    // cel podróży: _destinationX, _destinationY,
    // należy obliczyć siłę.

    // zaślepka
    Force result = {0.0, 0.0};
    return result;
}


void Robot::calculateVelocity()
{
    // tu odpalamy calculateForce i na podstawie wyliczonych wartości
    // siły oraz bieżących prędkości wyliczamy nowe prędkości
}



int32_t Robot::getLocalId() const
{
    return _localId;
}

void Robot::setLocalId(int32_t localId)
{
    _localId = localId;
}


int32_t Robot::getGlobalId() const
{
    return _globalId;
}

void Robot::setGlobalId(int32_t globalId)
{
    _globalId = globalId;
}


int32_t Robot::getXPos() const
{
    return _xPos;
}

void Robot::setXPos(int32_t xPos)
{
    _xPos = xPos;
}


int32_t Robot::getYPos() const
{
    return _yPos;
}

void Robot::setYPos(int32_t yPos)
{
    _yPos = yPos;
}


int32_t Robot::getXVel() const
{
    return _xVel;
}

void Robot::setXVel(int32_t xVel)
{
    _xVel = xVel;
}


int32_t Robot::getYVel() const
{
    return _yVel;
}

void Robot::setYVel(int32_t yVel)
{
    _yVel = yVel;
}


int32_t Robot::getDiameter() const
{
    return _diameter;
}

void Robot::setDiameter(int32_t diameter)
{
    _diameter = diameter;
}


bool Robot::getIsAllowedToLeaveField() const
{
    return _isAllowedToLeaveField;
}

void Robot::setIsAllowedToLeaveField(bool value)
{
    _isAllowedToLeaveField = value;
}


int32_t Robot::getNextFieldXPos() const
{
    return _nextFieldXPos;
}

void Robot::setNextFieldXPos(int32_t nextFieldXPos)
{
    _nextFieldXPos = nextFieldXPos;
}


int32_t Robot::getNextFieldYPos() const
{
    return _nextFieldYPos;
}

void Robot::setNextFieldYPos(int32_t nextFieldYPos)
{
    _nextFieldYPos = nextFieldYPos;
}


int32_t Robot::getDestinationX() const
{
    return _destinationX;
}

void Robot::setDestinationX(int32_t destinationX)
{
    _destinationX = destinationX;
}


int32_t Robot::getDestinationY() const
{
    return _destinationY;
}

void Robot::setDestinationY(int32_t destinationY)
{
    _destinationY = destinationY;
}



