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
    double ans = sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
    if(ans) return(ans);
    else return(0.00000000001);
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

    const double A = 1500,      //odpychanie ścian
                 B = 50,        //wyjazd
                 C = 20;       //drugi robot
    const double destPosWidth = 0.75;        //0-1, określa położenie potencjału docelowego w proporcji długości ściany, przez którą robot ma przejechać
    const double destPosDepth = 0.1;         //dodatnia wartość [0;1], określa odsunięcie potencjału w głąb docelowej komórki
    const double randomForce  = 0.01;        //losowa siła mnożona przez losowe [-0.5;0.5]

    //współrzędne robotów znormalizowane w fukcji wielkości pola, aby zawsze stosunek sił był ten sam
    const double myNormX = getXPos()/xFieldSize, myNormY = getYPos()/yFieldSize;
    const double normXFieldSize = 1, normYFieldSize = 1; //double, żeby nie robić wszędzie rzutowania :)

    Force result = {0.0, 0.0};

    /* odpychanie od ścian */
    //cos(alpha)*A*R^2
    result.X += ((normXFieldSize/2)-myNormX)/(distance(myNormX, myNormY, normXFieldSize/2, normYFieldSize/2))
               * A*pow(distance(myNormX, myNormY, normXFieldSize/2, normYFieldSize/2),2);
    //sin(alpha)*A*R^2
    result.Y += ((normYFieldSize/2)-myNormY)/(distance(myNormX, myNormY, normXFieldSize/2, normYFieldSize/2))
               * A*pow(distance(myNormX, myNormY, normXFieldSize/2, normYFieldSize/2),2);

    /* wyjazd z pola */
    if(_isAllowedToLeaveField)
    {
        double destX = 0, destY = 0;

        if(_nextFieldXPos==0 && _nextFieldYPos==-1) // w górę
        {
            destX = destPosWidth*normXFieldSize;
            destY = -destPosDepth;
        }

        if(_nextFieldXPos==1 && _nextFieldYPos==0) // w prawo
        {
            destX = normXFieldSize + destPosDepth;
            destY = destPosWidth*normYFieldSize;
        }

        if(_nextFieldXPos==0 && _nextFieldYPos==1) // w dół
        {
            destX = normXFieldSize - destPosWidth*normXFieldSize;
            destY = normYFieldSize + destPosDepth;
        }

        if(_nextFieldXPos==-1 && _nextFieldYPos==0) // w lewo
        {
            destX = -destPosDepth;
            destY = normYFieldSize - destPosWidth*normYFieldSize;
        }

        //cos(alpha)*B/R^2
        result.X += ((destX-myNormX)/distance(myNormX, myNormY, destX, destY))
                   * B/pow(distance(myNormX, myNormY, destX, destY),2);
        //sin(alpha)*B/R^2
        result.Y += (destY-myNormY)/distance(myNormX, myNormY, destX, destY)
                   * B/pow(distance(myNormX, myNormY, destX, destY),2);
    }

    /* drugi robot */
    if(secondRobot)
    {
        const double secRobNormX = secondRobot->getXPos()/xFieldSize, secRobNormY = secondRobot->getYPos()/yFieldSize;

        //cos(alpha)*C/R^2
        result.X += (myNormX-secRobNormX)/(distance(myNormX, myNormY, secRobNormX, secRobNormY))
                   * C/pow(distance(myNormX, myNormY, secRobNormX, secRobNormY),2);
        //sin(alpha)*C/R^2
        result.Y += (myNormY-secRobNormY)/(distance(myNormX, myNormY, secRobNormX, secRobNormY))
                   * C/pow(distance(myNormX, myNormY, secRobNormX, secRobNormY),2);
    }

    /* losowa składowa */
    result.X += ((rand()%1000)/1000 - 0.5)*randomForce*result.X;
    result.Y += ((rand()%1000)/1000 - 0.5)*randomForce*result.Y;

    return result;
}


void Robot::calculatePosition(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot, int timeDelay)
{
    // tu odpalamy calculateForce i na podstawie wyliczonych wartości
    // siły oraz bieżących prędkości wyliczamy nowe położenie
    const double timeStep = static_cast<double>(timeDelay)/1000;   //[s]

    const double robotMass = 1;     //[kg]
    const double maxVelocityX = 0.2*xFieldSize;
    const double maxVelocityY = 0.2*yFieldSize;
    const double frictionFactor = 0;
    const double brakingFactor = 0.3;

    bool         brake = false;

    Force force = calculateForce(xFieldSize, yFieldSize, secondRobot);

    /* Siła tłumiąca */
    if(force.X > abs(frictionFactor*robotMass*9.81))
        force.X += frictionFactor*(-sgn(_xVel))*robotMass*9.81;
    else
        brake = true;
    if(force.Y > abs(frictionFactor*robotMass*9.81))
        force.Y += frictionFactor*(-sgn(_yVel))*robotMass*9.81;
    else
        brake = true;

    /* Ograniczenie przemieszczenia zgodnie z maxVelocity */
    if((timeStep*_xVel + (force.X/robotMass)*pow(timeStep,2)/2) > maxVelocityX*timeStep)
    {
        _xPos = getXPos() + timeStep*maxVelocityX;
    }
    else if((timeStep*_xVel + (force.X/robotMass)*pow(timeStep,2)/2) < -maxVelocityX*timeStep)
    {
        _xPos = getXPos() - timeStep*maxVelocityX;
    }
    else
    {
        _xPos = getXPos() + timeStep*_xVel + (force.X/robotMass)*pow(timeStep,2)/2;
    }

    if(timeStep*_yVel + (force.Y/robotMass)*pow(timeStep,2)/2 > maxVelocityY*timeStep)
    {
        _yPos = getYPos() + timeStep*maxVelocityY;
    }
    else if(timeStep*_yVel + (force.Y/robotMass)*pow(timeStep,2)/2 < -maxVelocityY*timeStep)
    {
        _yPos = getYPos() - timeStep*maxVelocityY;
    }
    else
    {
        _yPos = getYPos() + timeStep*_yVel + (force.Y/robotMass)*pow(timeStep,2)/2;
    }

    _xVel += (force.X/robotMass)*timeStep;
    if(brake) _xVel *= brakingFactor;
    _yVel += (force.Y/robotMass)*timeStep;
    if(brake) _yVel *= brakingFactor;

    if(_xVel > maxVelocityX) _xVel = maxVelocityX;
    else if(_xVel < -maxVelocityX) _xVel = -maxVelocityX;
    if(_yVel > maxVelocityY) _yVel = maxVelocityY;
    else if(_yVel < -maxVelocityY) _yVel = -maxVelocityY;
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








