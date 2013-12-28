#include <QtGui/QApplication>
#include "klient.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    klient w;
    w.show();
    std::cout<<"A"<<std::endl;
    std::cout<<"B"<<std::endl;
    std::cout<<"C"<<std::endl;
    std::cout<<"D"<<std::endl;

    
    return a.exec();
}

