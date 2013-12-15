#include <QtGui/QApplication>
#include "serwermain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerwerMain w;
    w.show();
    
    return a.exec();
}
