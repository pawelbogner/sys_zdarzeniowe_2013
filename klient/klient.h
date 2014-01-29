#ifndef KLIENT_H
#define KLIENT_H

#include <QMainWindow>
#include "qclient.h"
#include "eter.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include "robot.h"

namespace Ui {
class klient;
}

class klient : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit klient(QWidget *parent = 0);
    QGraphicsScene Scene;
    ~klient();
    

public slots:
    void addRobotToSceneSlot(int32_t id); // wywolywane przez addRobotToSceneSignal w Ether
    //void register_robot_id(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y);
    void redrawScene(void); // wywolywane przez redrawScene w Ether
    void drawSceneWithLines(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y); // wywolywane przez drawSceneWithLines w Ether
    void registerNextRobot(void); // wywolywane przez robotProcessedSignal w Ether

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void response_sector  (int32_t id, int32_t, int32_t, eSectorRequestResponse response, int32_t); // wywolywane przez response_sector w qclient
    void go_to            (int32_t id, int32_t goto_x, int32_t goto_y); // wywolywane przez goToEtherSignal w Ether

    void on_pushButton_4_clicked();

private:
    Ui::klient *ui;
    QClient *client;
    Ether *ourEther;
    std::map<int32_t, boost::shared_ptr<QGraphicsEllipseItem> > robotsOnScene;
    QTransform Translation;
    std::vector<RobotToRegister> robotsToRegister;
};

#endif // KLIENT_H

