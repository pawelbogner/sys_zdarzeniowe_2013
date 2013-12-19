#ifndef ETER_H
#define ETER_H

#include <QObject>
#include<vector>
#include<stdint.h>
#include"field.h"

class Ether : public QObject
{
    Q_OBJECT
public:
//    Ether(int32_t fields_x, int32_t fields_y, int32_t fieldXSize, int32_t fieldYSize);
    Ether(QObject *parent = 0);
    void start();
private:
    std::vector<Field> fields;
    std::vector<boost::shared_ptr<Robot> > _allRobotsOnScene;

    void advanceTime();

public slots:
    // BF0: jak od serwera odebrana jest odpowiedz na rejstrowanie robota, to automatycznie zostaje wyemitowany sygnał "register_robot_id", ktory to polaczony jest z tym o to slotem. ten o to slot odpowiada za dodanie robota do listy obiektu Ether.
    void registerRobotInEter(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y);
};

#endif // ETER_H

