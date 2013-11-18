#include "mapka.h"
#include "ui_mapka.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QTransform>

Mapka::Mapka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mapka)
{
    ui->setupUi(this);

    Robot1= Scena.addEllipse(10,10,10,10);
    Robot2= Scena.addEllipse(0,0,10,10);

    this->ui->WidokSceny->setScene(&Scena);
    krok=5;
    Przesuniecie.translate(0,0);
}

Mapka::~Mapka()
{
    delete ui;
}

void Mapka::on_gora_clicked()
{
    Przesuniecie.translate(0,-krok);
    Robot1->setTransform(Przesuniecie);
}

void Mapka::on_prawo_clicked()
{
    Przesuniecie.translate(krok,0);
    Robot1->setTransform(Przesuniecie);
}

void Mapka::on_dol_clicked()
{
    Przesuniecie.translate(0,krok);
    Robot1->setTransform(Przesuniecie);
}

void Mapka::on_lewo_clicked()
{
    Przesuniecie.translate(-krok,0);
    Robot1->setTransform(Przesuniecie);
}

void Mapka::on_Zoom_valueChanged(int value)
{
    krok=value;
}
