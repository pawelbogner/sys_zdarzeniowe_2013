#include <QtGui/QApplication>
#include "klient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    klient w;
    w.show();
    
    return a.exec();
}

