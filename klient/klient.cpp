#include "klient.h"
#include "ui_klient.h"
#include "defines.h"
#include <iostream>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>

klient::klient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::klient)
{
    ui->setupUi(this);

    this->client = new QClient(this);
    this->ourEther = new Ether(this->client,this);
    connect(this->client, SIGNAL(register_robot_id(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)), this->ourEther, SLOT(registerRobotInEther(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)));
    connect(this->client, SIGNAL(response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t)), this, SLOT(response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t)));
    connect(this->client, SIGNAL(go_to(int32_t,int32_t,int32_t)), this->ourEther, SLOT(setRobotNextField(int32_t, int32_t, int32_t)));
    connect(this->ourEther, SIGNAL(goToEtherSignal(int32_t,int32_t,int32_t)), this, SLOT(go_to(int32_t, int32_t, int32_t)));
    connect(this->ourEther, SIGNAL(addRobotToSceneSignal(int32_t)), this, SLOT(addRobotToSceneSlot(int32_t)));
    connect(this->ourEther, SIGNAL(redrawScene()), this, SLOT(redrawScene()));
    connect(this->ourEther, SIGNAL(drawSceneWithLines(int32_t,int32_t,int32_t,int32_t)), this, SLOT(drawSceneWithLines(int32_t,int32_t,int32_t,int32_t)));
    this->ui->graphicsView->setScene(&Scene);
}

klient::~klient()
{
    delete ui;
    delete client;
    delete ourEther;
}

void klient::addRobotToSceneSlot(int32_t id)
{
    boost::shared_ptr<QGraphicsEllipseItem> ellipse = boost::make_shared<QGraphicsEllipseItem>(-10, -10, DIAMETER, DIAMETER);
    robotsOnScene.insert(std::pair<int32_t, boost::shared_ptr<QGraphicsEllipseItem> >(id, ellipse));
    Scene.addItem(robotsOnScene.find(id)->second.get());
    ui->rr_id->setText(QString("%1").arg(id));
    ui->rr_ssx->setText(QString("%1").arg(ourEther->getFields().at(0).xSize()));
    ui->rr_ssy->setText(QString("%1").arg(ourEther->getFields().at(0).ySize()));

}

void klient::on_pushButton_clicked()
{
    std::cerr<<this->client->connect_to_host(this->ui->host->text(), this->ui->port->value(), 2000)<<std::endl;
    ourEther->start(OURTIMEDELAYMS);
}

void klient::on_pushButton_2_clicked()
{
    this->client->disconnect_from_host();
}

void klient::on_pushButton_3_clicked()
{
    this->client->register_robot(this->ui->rr_lid->value(), this->ui->rr_dia->value());
}

void klient::on_pushButton_4_clicked()
{
    eSectorRequest request=static_cast<eSectorRequest>(this->ui->s_req->value());
    this->client->request_sector(this->ui->s_id->value(), this->ui->s_x->value(), this->ui->s_y->value(), request);
}


void klient::redrawScene()
{
    BOOST_FOREACH(Field field, ourEther->getFields()){
        BOOST_FOREACH(boost::shared_ptr<Robot> robot, field.getRobotsOnField()){
            robotsOnScene[robot->getGlobalId()]->setRect(      robot->getXPos() - DIAMETER/2 + field.xSize()*field.xCoord(),
                                                               robot->getYPos() - DIAMETER/2 + field.ySize()*field.yCoord(),
                                                               robot->getDiameter(),
                                                               robot->getDiameter()
                                                               );
        }
    }
}

void klient::drawSceneWithLines(int32_t size_x, int32_t size_y, int32_t sector_size_x, int32_t sector_size_y)
{
    Scene.setSceneRect(0, 0, sector_size_x*size_x, sector_size_y*size_y);
    for(int i=0; i<=size_x; ++i) //kreski pionowe
        Scene.addLine(i*sector_size_x, 0, i*sector_size_x, size_y*sector_size_y);
    for(int i=0; i<=size_y; ++i) //kreski poziome
        Scene.addLine(0, i*sector_size_y, size_x*sector_size_x, i*sector_size_y);
}


void klient::response_sector(int32_t id, int32_t, int32_t, eSectorRequestResponse response, int32_t)
{
    boost::shared_ptr<Robot> robot = ourEther->getRobotWithMatchingId(id);
    if(response==eAffirmative)
    {
        robot->setIsAllowedToLeaveField(true);
        ui->s_resp->setText("Affirmative");
    }
    else {
        robot->setIsAllowedToLeaveField(false);
        ui->s_resp->setText("Negative");
    }
}

void klient::go_to(int32_t id, int32_t goto_x, int32_t goto_y)
{
    this->ui->gt_id->setText(QString("%1").arg(id));
    this->ui->gt_x->setText(QString("%1").arg(goto_x));
    this->ui->gt_y->setText(QString("%1").arg(goto_y));
}

