#ifndef ETER_H
#define ETER_H

#include <QObject>
#include <QTimer>
#include <vector>
#include <stdint.h>
#include "field.h"
#include "robot.h"


class Ether : public QObject
{
    Q_OBJECT
public:
//    Ether(int32_t fields_x, int32_t fields_y, int32_t fieldXSize, int32_t fieldYSize);
    Ether(QObject *parent = 0);
    void start(int timeDelay);

    std::vector<Field> getFields();
    void createFields(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y);
private:
    std::vector<Field> fields;
    std::vector<boost::shared_ptr<Robot> > _allRobotsOnScene;
    QTimer *timer;
    bool fieldsAreCreated;
    int _timeDelay; //[ms]timer->start(_timeDelay);


    boost::shared_ptr<Robot> getRobotWithMatchingId(int32_t id);

signals:
    void addRobotToSceneSignal(int32_t id, int32_t x, int32_t y);
    void redrawScene(void);
    void drawSceneWithLines(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y);

public slots:
    void registerRobotInEther(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y);
    void setRobotNextField(int32_t id, int32_t nextFieldX, int32_t nextFieldY);
    void advanceTime();
};

#endif // ETER_H

