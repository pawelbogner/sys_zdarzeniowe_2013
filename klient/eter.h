#ifndef ETER_H
#define ETER_H

#include <QObject>
#include <QTimer>
#include <vector>
#include <stdint.h>
#include "field.h"
#include "robot.h"
#include "defines.h"


class Ether : public QObject
{
    Q_OBJECT
public:
//    Ether(int32_t fields_x, int32_t fields_y, int32_t fieldXSize, int32_t fieldYSize);
    Ether(QClient *client, QObject *parent = 0);
    void start(int timeDelay);

    std::vector<Field> &getFields();
    void createFields(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y);
    boost::shared_ptr<Robot> getRobotWithMatchingId(int32_t id);
    Field *findFieldWithCoords(int32_t x, int32_t y);
private:
    std::vector<Field> fields;
    std::vector<boost::shared_ptr<Robot> > _allRobotsOnScene;
    QTimer *timer;
    bool fieldsAreCreated;
    int _timeDelay; //[ms]timer->start(_timeDelay);
    QClient *_client;


signals:
    void addRobotToSceneSignal(int32_t id); // wywoluje addRobotToSceneSlot w klient
    void redrawScene(void); // wywoluje redrawScene w klient
    void drawSceneWithLines(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y); // wywoluje drawSceneWithLines w klient
    void goToEtherSignal(int32_t id, int32_t goto_x, int32_t goto_y); // wywoluje go_to w klient

public slots:
    void registerRobotInEther(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y); // wywolywane przez register_robot_id w qclient
    void setRobotNextField(int32_t id, int32_t nextFieldX, int32_t nextFieldY); // wywolywane przez go_to w qclient
    void advanceTime(); // z timera
};

#endif // ETER_H

