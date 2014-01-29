#include "serwermain.h"
#include "ui_serwermain.h"

SerwerMain::SerwerMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerwerMain)
{
    ui->setupUi(this);

    this->serwer = new QSerwer(25, 25, 10, 10, this);
    //connect(this->serwer, SIGNAL(data(QBytes)), this, SLOT(data(QBytes)));
}

SerwerMain::~SerwerMain()
{
    delete this->serwer;
    delete ui;
}

void SerwerMain::on_pushButton_clicked()
{
    this->serwer->StartServer(this->ui->spinBox->value());
}

void SerwerMain::on_pushButton_4_clicked()
{
    this->serwer->response_sector(this->ui->se_id->value(), this->ui->se_x->value(), this->ui->se_y->value(), this->ui->se_resp->value(), this->ui->se_cli->value(), this->ui->gt_x->value(), this->ui->gt_y->value());
}

void SerwerMain::on_se_resp_valueChanged(int arg1)
{
    serwer->responseBF=arg1;
}
