#ifndef ETER_H
#define ETER_H

#include<vector>
#include"field.h"

class Ether
{
public:
    Ether(int fields_x, int fields_y, double fieldXSize, double fieldYSize);
    void start();
private:
    std::vector<Field> fields;
    void advanceTime();
};

#endif // ETER_H
