#ifndef SCENA_H
#define SCENA_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView> // zeby polaczyc z okienkiem wizualizacji
#include <QTransform>
#include <list>

class Scena
{

public:
    Scena();
    ~Scena();

    QGraphicsScene scenaRobotyczna;

    list<QGraphicsEllipseItem> listaRobotow; //tu sa figury geometryczne reprezentujace nasze roboty
    QTransform przesunecie;

public slots:

};

#endif // SCENA_H
