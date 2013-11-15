#include "robot.h"

Robot::Robot()
{
}

int Robot::id() const
{
    return _id;
}

void Robot::setId(int id)
{
    _id = id;
}
double Robot::xPos() const
{
    return _xPos;
}

void Robot::setXPos(double xPos)
{
    _xPos = xPos;
}
double Robot::yPos() const
{
    return _yPos;
}

void Robot::setYPos(double yPos)
{
    _yPos = yPos;
}
double Robot::xVel() const
{
    return _xVel;
}

void Robot::setXVel(double xVel)
{
    _xVel = xVel;
}
double Robot::yVel() const
{
    return _yVel;
}

void Robot::setYVel(double yVel)
{
    _yVel = yVel;
}
double Robot::diameter() const
{
    return _diameter;
}

void Robot::setDiameter(double diameter)
{
    _diameter = diameter;
}





