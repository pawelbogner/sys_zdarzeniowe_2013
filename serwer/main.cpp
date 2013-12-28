#include <QtGui/QApplication>
#include "serwermain.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    SerwerMain universe;
    universe.show();
    
    return application.exec();
}
