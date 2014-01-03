#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include<boost/shared_ptr.hpp>
#include<vector>
#include<inttypes.h>
#include<stdint.h>
#include"robot.h"
#include "qclient.h"
//#include"klient.h"

class Ether;

class Field{
public:
    Field(int32_t xSize, int32_t ySize, int32_t xCoord, int32_t yCoord, Ether *ourEther);

    //bool informServerOfRobotLeaving(boost::shared_ptr<Robot> robotLeaving, Field nextField);
    // robotDemandsFieldAccess to metoda wywolywana przez pole, na ktorym aktualnie znajduje sie robot, ktory
    // chce przejechac na pole nextField; metoda pyta o pozwolenie przez wywolanie reserve() w polu nextField
    //bool robotDemandsFieldAccess(boost::shared_ptr<Robot> robotWishingToLeave, Field nextField);
    //void reserve(boost::shared_ptr<Robot> robotWishingToEnter);
    void removeRobot(boost::shared_ptr<Robot> robot);
    void addRobot(boost::shared_ptr<Robot> robot);
    void computeOneIterationOfMotion(int timeDelay); // tu liczymy potencjaly
    bool setRobotNextField(int32_t globalId, int32_t nextFieldX, int32_t nextFieldY);

    std::vector<boost::shared_ptr<Robot> > &getRobotsOnField();

    int32_t xSize() const;
    int32_t ySize() const;

    int32_t xCoord() const;
    int32_t yCoord() const;
    void reallocateRobot(boost::shared_ptr<Robot> robot);
private:
    int32_t _xSize, _ySize; //w centymetrach
    int32_t _xCoord, _yCoord;
    std::vector<boost::shared_ptr<Robot> > _robotsOnField;
    //boost::shared_ptr<QClient> _client;
    boost::shared_ptr<Robot> getRobotWithMatchingId(int32_t id);
    Ether *_ourEther;
};

#endif // FIELD_H

