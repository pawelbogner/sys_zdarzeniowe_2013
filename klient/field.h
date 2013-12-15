#ifndef FIELD_H
#define FIELD_H

#include<boost/shared_ptr.hpp>
#include<vector>
#include"robot.h"
#include<inttypes.h>
#include<stdint.h>


class Field {
public:
    Field(int32_t xSize, int32_t ySize);

    bool informServerOfRobotLeaving(boost::shared_ptr<Robot> robotLeaving);
    // robotDemandsFieldAccess to metoda wywolywana przez pole, na ktorym aktualnie znajduje sie robot, ktory
    // chce przejechac na pole nextField; metoda pyta o pozwolenie przez wywolanie reserve() w polu nextField
    bool robotDemandsFieldAccess(boost::shared_ptr<Robot> robotWishingToLeave, Field nextField);
    bool reserve();
    void removeRobot(boost::shared_ptr<Robot> robot);
    void addRobot(boost::shared_ptr<Robot> robot);
    void computeOneIterationOfMotion(); // tu liczymy potencjaly

private:
    double _xSize, _ySize;
    std::vector<boost::shared_ptr<Robot> > _robots;

};

#endif // FIELD_H
