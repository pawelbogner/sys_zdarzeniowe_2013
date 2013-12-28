#ifndef ROBOT_H
#define ROBOT_H

#include<stdint.h>


struct Force {
    double X, Y;
};


class Robot
{
public:
    Robot(int32_t local_id, int32_t id, int32_t size_x, int32_t size_y);
    Force calculateForce();

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

private:
    int32_t _diameter;
    int32_t _localId;
    int32_t _globalId;
    int32_t _xVel, _yVel;
    int32_t _xPos, _yPos;

    bool _isAllowedToLeaveField;
    int32_t _nextFieldXPos;
    int32_t _nextFieldYPos;
};

#endif // ROBOT_H


