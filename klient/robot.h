#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
public:
    Robot();
    int getId() const;
    void setId(int id);

    double getXPos() const;
    void setXPos(double xPos);

    double getYPos() const;
    void setYPos(double yPos);

    double getXVel() const;
    void setXVel(double xVel);

    double getYVel() const;
    void setYVel(double yVel);

    double getDiameter() const;
    void setDiameter(double diameter);

private:
    int _id;
    double _xPos, _yPos;
    double _xVel, _yVel;
    double _diameter;
};

#endif // ROBOT_H
