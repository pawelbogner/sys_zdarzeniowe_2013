/********************************************************************************
** Form generated from reading UI file 'mapka.ui'
**
** Created: Mon Nov 18 16:28:10 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPKA_H
#define UI_MAPKA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mapka
{
public:
    QWidget *centralWidget;
    QGraphicsView *WidokSceny;
    QSlider *Zoom;
    QGraphicsView *OknoZoom;
    QPushButton *gora;
    QPushButton *prawo;
    QPushButton *lewo;
    QPushButton *dol;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mapka)
    {
        if (Mapka->objectName().isEmpty())
            Mapka->setObjectName(QString::fromUtf8("Mapka"));
        Mapka->resize(500, 400);
        centralWidget = new QWidget(Mapka);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WidokSceny = new QGraphicsView(centralWidget);
        WidokSceny->setObjectName(QString::fromUtf8("WidokSceny"));
        WidokSceny->setGeometry(QRect(230, 70, 250, 250));
        Zoom = new QSlider(centralWidget);
        Zoom->setObjectName(QString::fromUtf8("Zoom"));
        Zoom->setGeometry(QRect(40, 50, 160, 29));
        Zoom->setMaximum(10);
        Zoom->setValue(5);
        Zoom->setOrientation(Qt::Horizontal);
        OknoZoom = new QGraphicsView(centralWidget);
        OknoZoom->setObjectName(QString::fromUtf8("OknoZoom"));
        OknoZoom->setGeometry(QRect(40, 130, 150, 150));
        gora = new QPushButton(centralWidget);
        gora->setObjectName(QString::fromUtf8("gora"));
        gora->setGeometry(QRect(70, 100, 98, 27));
        prawo = new QPushButton(centralWidget);
        prawo->setObjectName(QString::fromUtf8("prawo"));
        prawo->setGeometry(QRect(190, 150, 31, 101));
        lewo = new QPushButton(centralWidget);
        lewo->setObjectName(QString::fromUtf8("lewo"));
        lewo->setGeometry(QRect(0, 150, 31, 101));
        dol = new QPushButton(centralWidget);
        dol->setObjectName(QString::fromUtf8("dol"));
        dol->setGeometry(QRect(70, 290, 98, 27));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(70, 20, 61, 23));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(5));
        Mapka->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mapka);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 25));
        Mapka->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mapka);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Mapka->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mapka);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Mapka->setStatusBar(statusBar);

        retranslateUi(Mapka);
        QObject::connect(Zoom, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Mapka);
    } // setupUi

    void retranslateUi(QMainWindow *Mapka)
    {
        Mapka->setWindowTitle(QApplication::translate("Mapka", "Mapka", 0, QApplication::UnicodeUTF8));
        gora->setText(QApplication::translate("Mapka", "^", 0, QApplication::UnicodeUTF8));
        prawo->setText(QApplication::translate("Mapka", ">", 0, QApplication::UnicodeUTF8));
        lewo->setText(QApplication::translate("Mapka", "<", 0, QApplication::UnicodeUTF8));
        dol->setText(QApplication::translate("Mapka", "v", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mapka: public Ui_Mapka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPKA_H
