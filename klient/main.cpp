#include <QtGui/QApplication>
#include "klient.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    klient appCli;
    appCli.show();
    return app.exec();
}

