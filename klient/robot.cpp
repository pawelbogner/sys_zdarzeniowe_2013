#include "robot.h"
#include "defines.h"

int sgn(double val)
{
    if(val<0) return -1;
    if(val>0) return 1;
    else return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
    return(sqrt( pow((x2-x1),2) + pow((y2-y1),2) ));
}

Robot::Robot(int32_t local_id, int32_t id):
    _localId(local_id), _diameter(DIAMETER), _globalId(id), _isAllowedToLeaveField(false),
    _xPos(0), _yPos(0), _xVel(0), _yVel(0), _nextFieldXPos(0), _nextFieldYPos(0), _prevFieldReleased(true),
    _prevFieldXPos(0), _prevFieldYPos(0)
{
    srand (time(NULL));
}

Force Robot::calculateForce(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot)
{
    // liczy siłę działającą na robota

    const double Ax = 0.1, Ay = 0.1, Bx = 500000, By = 500000, Cx = 10000, Cy = 10000;
    const double destPosWidth = 0.75;        //0-1, określa położenie potencjału docelowego w proporcji długości ściany, przez którą robot ma przejechać
    const double destPosDepth = DIAMETER;    //dodatnia wartość określa odsunięcie potencjału w głąb docelowej komórki (w proporcji długości ściany komórki)
    const double randomForce  = 0.01;        //losowa siła mnożona przez losowe 0-1

    Force result = {0.0, 0.0};

    /* odpychanie od ścian */
    //R^2, okrągłe poziomice
    result.X += Ax*sgn(xFieldSize/2 - getXPos())*(pow((xFieldSize/2 - getXPos()),2));
    result.Y += Ay*sgn(yFieldSize/2 - getYPos())*(pow((yFieldSize/2 - getYPos()),2));

    //R, okrągłe poziomice
    //result.X += A*(xFieldSize/2 - getXPos());
    //result.Y += A*(yFieldSize/2 - getYPos());

    //R^2, prostokątne poziomice
    //result.X += A*(pow((xFieldSize - getXPos()),2) - pow(getXPos(),2));
    //result.Y += A*(pow((yFieldSize - getYPos()),2) - pow(getYPos(),2));

    /* wyjazd z pola */
    if(_isAllowedToLeaveField)
    {
        double destX = 0, destY = 0;

        if(_nextFieldXPos==0 && _nextFieldYPos==-1) // w górę
        {
            destX = destPosWidth*xFieldSize;
            destY = -destPosDepth;
        }

        if(_nextFieldXPos==1 && _nextFieldYPos==0) // w prawo
        {
            destX = xFieldSize + destPosDepth;
            destY = destPosWidth*yFieldSize;
        }

        if(_nextFieldXPos==0 && _nextFieldYPos==1) // w dół
        {
            destX = xFieldSize - destPosWidth*xFieldSize;
            destY = yFieldSize + destPosDepth;
        }

        if(_nextFieldXPos==-1 && _nextFieldYPos==0) // w lewo
        {
            destX = -destPosDepth;
            destY = yFieldSize - destPosWidth*yFieldSize;
        }

        //cos(alpha)*B/R^2
        result.X += (distance(getXPos(), getYPos(), destX, destY)/(destY-getYPos()))
                   * Bx/pow(distance(getXPos(), getYPos(), destX, destY),2);
        //sin(alpha)*B/R^2
        result.Y += (distance(getXPos(), getYPos(), destX, destY)/(destX-getXPos()))
                   * By/pow(distance(getXPos(), getYPos(), destX, destY),2);
    }

    /* drugi robot */
    if(secondRobot)
    {
        //cos(alpha)*C/R^2
        result.X += (getXPos()-secondRobot->getXPos())/(distance(getXPos(), getYPos(), secondRobot->getXPos(), secondRobot->getYPos()))
                   * Cx/pow(distance(getXPos(), getYPos(), secondRobot->getXPos(), secondRobot->getYPos()),2);
        //sin(alpha)*C/R^2
        result.Y += (getYPos()-secondRobot->getYPos())/(distance(getXPos(), getYPos(), secondRobot->getXPos(), secondRobot->getYPos()))
                   * Cy/pow(distance(getXPos(), getYPos(), secondRobot->getXPos(), secondRobot->getYPos()),2);
    }

    /* losowa składowa */
    //result.X += ((rand()%1000)/1000 - 0.5)*randomForce*result.X;
    //result.Y += ((rand()%1000)/1000 - 0.5)*randomForce*result.Y;

    return result;
}


void Robot::calculatePosition(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot, int timeDelay)
{
    // tu odpalamy calculateForce i na podstawie wyliczonych wartości
    // siły oraz bieżących prędkości wyliczamy nowe położenie
    const double timeStep = static_cast<double>(timeDelay)/1000;   //[s]

    const double robotMass = 1;     //[kg]
    const double maxVelocity = 2;   //[m/s]

    Force force = calculateForce(xFieldSize, yFieldSize, secondRobot);

    _xPos = getXPos() + timeStep*_xVel + (force.X/robotMass)*pow(timeStep,2)/2;
    _yPos = getYPos() + timeStep*_yVel + (force.Y/robotMass)*pow(timeStep,2)/2;

    _xVel += (force.X/robotMass)*timeStep;
    _yVel += (force.Y/robotMass)*timeStep;

    if(_xVel > maxVelocity) _xVel = maxVelocity;
    else if(_xVel < -maxVelocity) _xVel = -maxVelocity;
    if(_yVel > maxVelocity) _yVel = maxVelocity;
    else if(_yVel < -maxVelocity) _yVel = -maxVelocity;
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
int32_t Robot::getPrevFieldXPos() const
{
    return _prevFieldXPos;
}

void Robot::setPrevFieldXPos(const int32_t &prevFieldXPos)
{
    _prevFieldXPos = prevFieldXPos;
}
int32_t Robot::getPrevFieldYPos() const
{
    return _prevFieldYPos;
}

void Robot::setPrevFieldYPos(const int32_t &prevFieldYPos)
{
    _prevFieldYPos = prevFieldYPos;
}








