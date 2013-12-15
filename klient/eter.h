#ifndef ETER_H
#define ETER_H

#include<vector>
#include"field.h"
#include<stdint.h>

class Ether
{
public:
    Ether(int32_t fields_x, int32_t fields_y, int32_t fieldXSize, int32_t fieldYSize);
    void start();
private:
    std::vector<Field> fields;
    std::vector<boost::shared_ptr<Robot> > _allRobotsOnScene;

    void advanceTime();
};

#endif // ETER_H
