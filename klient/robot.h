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
    Robot(int32_t local_id, int32_t id);
    Force calculateForce(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot);

    void calculatePosition(int32_t xFieldSize, int32_t yFieldSize, boost::shared_ptr<Robot> secondRobot, int timeDelay);

    double getXPos() const;
    void setXPos(double xPos);

    double getYPos() const;
    void setYPos(double yPos);

    double getXVel() const;
    void setXVel(double xVel);

    double getYVel() const;
    void setYVel(double yVel);

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

    bool getPrevFieldReleased() const;
    void setPrevFieldReleased(bool prevFieldReleased);

private:
    int32_t _localId;
    int32_t _diameter;
    int32_t _globalId;

    bool _isAllowedToLeaveField;
    double _xPos, _yPos; // względem kratki
    double _xVel, _yVel;
    int32_t _nextFieldXPos;
    int32_t _nextFieldYPos;
    bool _prevFieldReleased;
    int32_t _prevFieldXPos;
    int32_t _prevFieldYPos;
};

#endif // ROBOT_H


