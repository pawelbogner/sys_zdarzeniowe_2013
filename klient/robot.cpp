#include "robot.h"
#include "defines.h"

int sgn(double val)
{
    if(val<0) return -1;
    if(val>0) return 1;
    else return 0;
}

Robot::Robot(int32_t local_id, int32_t id):
    _localId(local_id), _diameter(DIAMETER), _globalId(id), _isAllowedToLeaveField(false),
    _xPos(0), _yPos(0), _xVel(0), _yVel(0), _nextFieldXPos(0), _nextFieldYPos(0), _prevFieldReleased(true),
    _prevFieldXPos(0), _prevFieldYPos(0)
{ }

Force Robot::calculateForce(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot)
{
    // liczy siłę działającą na robota
    const double doNotDivideByZero = 0.0001;

    const double A = 10, B = 0, C = 0;
    const double destPosWidth = 0.75;   //0-1, określa położenie potencjału docelowego w proporcji długości ściany, przez którą robot ma przejechać
    const double destPosDepth = 0.1;    //0-1, dodatnia wartość określa odsunięcie potencjału w głąb docelowej komórki (w proporcji długości ściany komórki)
    Force result = {0.0, 0.0};

    /* odpychanie od ścian */
    result.X += A/(pow((xFieldSize - getXPos()),2) - pow(getXPos(),2) + doNotDivideByZero);
    result.Y += A/(pow((yFieldSize - getYPos()),2) - pow(getYPos(),2) + doNotDivideByZero);

    /* wyjazd z pola */
    if(_isAllowedToLeaveField)
    {
        double destX = 0, destY = 0;

        if(_nextFieldXPos==0 && _nextFieldYPos==-1)
        {
            destX = destPosWidth*xFieldSize;
            destY = -destPosDepth;
        }

        if(_nextFieldXPos==1 && _nextFieldYPos==0)
        {
            destX = xFieldSize + destPosDepth;
            destY = destPosWidth*yFieldSize;
        }

        if(_nextFieldXPos==0 && _nextFieldYPos==1)
        {
            destX = xFieldSize - destPosWidth*xFieldSize;
            destY = yFieldSize + destPosDepth;
        }

        if(_nextFieldXPos==-1 && _nextFieldYPos==0)
        {
            destX = -destPosDepth;
            destY = yFieldSize - destPosWidth*yFieldSize;
        }

        result.X += B/(sgn(destX - getXPos())*pow((destX - getXPos()),2) + doNotDivideByZero);
        result.Y += B/(sgn(destY - getYPos())*pow((destY - getYPos()),2) + doNotDivideByZero);
    }

    /* drugi robot */
    if(secondRobot)
    {
        result.X += C/(sgn(getXPos() - secondRobot->getXPos())*pow((getXPos() - secondRobot->getXPos()),2) + doNotDivideByZero);     //Żeby nigdy nie było dzielenia przez zero :)
        result.Y += C/(sgn(getYPos() - secondRobot->getYPos())*pow((getYPos() - secondRobot->getYPos()),2) + doNotDivideByZero);
    }

    return result;
}


void Robot::calculatePosition(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot, int timeDelay)
{
    // tu odpalamy calculateForce i na podstawie wyliczonych wartości
    // siły oraz bieżących prędkości wyliczamy nowe położenie
    const double timeStep = static_cast<double>(timeDelay)/1000;   //[s]

    const double robotMass = 0.01;     //[kg]
    const double maxVelocity = 1;   //[m/s]

    Force force = calculateForce(xFieldSize, yFieldSize, secondRobot);

    _xPos = getXPos() + timeStep*_xVel + (force.X/robotMass)*pow(timeStep,2)/2;
    _yPos = getYPos() + timeStep*_yVel + (force.Y/robotMass)*pow(timeStep,2)/2;

    _xVel += (force.X/robotMass)*timeStep;
    _yVel += (force.Y/robotMass)*timeStep;
    if(_xVel > maxVelocity) _xVel = maxVelocity;
    if(_yVel > maxVelocity) _yVel = maxVelocity;
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


double Robot::getXPos() const
{
    return _xPos;
}

void Robot::setXPos(double xPos)
{
    _xPos = xPos;
}


double Robot::getYPos() const
{
    return _yPos;
}

void Robot::setYPos(double yPos)
{
    _yPos = yPos;
}


double Robot::getXVel() const
{
    return _xVel;
}

void Robot::setXVel(double xVel)
{
    _xVel = xVel;
}


double Robot::getYVel() const
{
    return _yVel;
}

void Robot::setYVel(double yVel)
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

bool Robot::getPrevFieldReleased() const
{
    return _prevFieldReleased;
}

void Robot::setPrevFieldReleased(bool prevFieldReleased)
{
    _prevFieldReleased = prevFieldReleased;
}






