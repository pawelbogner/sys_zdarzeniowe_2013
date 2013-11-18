#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include "ui_mapka.h"
#include "mapka.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mapka w;
    
    w.show();
    
    return a.exec();
}
