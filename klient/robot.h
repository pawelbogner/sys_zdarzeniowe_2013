#ifndef ROBOT_H
#define ROBOT_H

#include<stdint.h>
#include<cmath>
#include<boost/shared_ptr.hpp>


struct Force {
    double X, Y;
};


class Robot
{
public:
    Robot(int32_t local_id, int32_t id, int32_t size_x, int32_t size_y);
    Force calculateForce(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot);

    void calculateVelocity();

    int32_t getXPos() const;
    void setXPos(int32_t xPos);

    int32_t getYPos() const;
    void setYPos(int32_t yPos);

    int32_t getXVel() const;
    void setXVel(int32_t xVel);

    int32_t getYVel() const;
    void setYVel(int32_t yVel);

    int32_t getDiameter() const;
    void setDiameter(int32_t diameter);

    int32_t getGlobalId() const;
    void setGlobalId(int32_t globalId);

    int32_t getLocalId() const;
    void setLocalId(int32_t localId);

    bool getIsAllowedToLeaveField() const;
    void setIsAllowedToLeaveField(bool value);

    int32_t getNextFieldXPos() const;
    void setNextFieldXPos(int32_t nextFieldXPos);

    int32_t getNextFieldYPos() const;
    void setNextFieldYPos(int32_t nextFieldYPos);

    int32_t getDestinationX() const;
    void setDestinationX(int32_t destinationX);

    int32_t getDestinationY() const;
    void setDestinationY(int32_t destinationY);

private:
    int32_t _diameter;
    int32_t _localId;
    int32_t _globalId;
    int32_t _xVel, _yVel;
    int32_t _xPos, _yPos;

    bool _isAllowedToLeaveField;
    int32_t _nextFieldXPos;
    int32_t _nextFieldYPos;

    int32_t _destinationX;
    int32_t _destinationY;
};

#endif // ROBOT_H


