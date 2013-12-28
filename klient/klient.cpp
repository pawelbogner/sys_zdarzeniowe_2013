#include "klient.h"
#include "ui_klient.h"
#include <iostream>

klient::klient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::klient)
{
    ui->setupUi(this);

    this->client = new QClient(this);
    this->ourEther = new Ether(this);
    connect(this->client, SIGNAL(register_robot_id(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)), this->ourEther, SLOT(registerRobotInEter(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t)));
    connect(this->client, SIGNAL(response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t)), this, SLOT(response_sector(int32_t,int32_t,int32_t,eSectorRequestResponse,int32_t)));
    connect(this->client, SIGNAL(go_to(int32_t,int32_t,int32_t)), this->ourEther, SLOT(setRobotNextField(int32_t, int32_t, int32_t)));

    this->ui->graphicsView->setScene(&Scene);
}

klient::~klient()
{
    delete ui;
}

void klient::on_pushButton_clicked()
{
    std::cerr<<this->client->connect_to_host(this->ui->host->text(), this->ui->port->value(), 2000)<<std::endl;
}

void klient::on_pushButton_2_clicked()
{
    this->client->disconnect_from_host();
}

void klient::on_pushButton_3_clicked()
{
    this->client->register_robot(this->ui->rr_lid->value(), this->ui->rr_dia->value());
}


void klient::register_robot_id(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y)
{
    this->ui->rr_id->setText(QString("%1").arg(id));
    this->ui->rr_ssx->setText(QString("%1").arg(sector_size_x));
    this->ui->rr_ssy->setText(QString("%1").arg(sector_size_y));
}


void klient::response_sector(int32_t id, int32_t x, int32_t y, eSectorRequestResponse response, int32_t clients)
{

}

void klient::go_to(int32_t id, int32_t goto_x, int32_t goto_y)
{
    this->ui->gt_id->setText(QString("%1").arg(id));
    this->ui->gt_x->setText(QString("%1").arg(goto_x));
    this->ui->gt_y->setText(QString("%1").arg(goto_y));
}

