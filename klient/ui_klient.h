/********************************************************************************
** Form generated from reading UI file 'klient.ui'
**
** Created: Wed Nov 20 14:36:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KLIENT_H
#define UI_KLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_klient
{
public:
    QWidget *centralWidget;
    QLineEdit *host;
    QLabel *label;
    QSpinBox *port;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *rr_lid;
    QSpinBox *rr_dia;
    QLabel *label_5;
    QLabel *rr_id;
    QLabel *label_7;
    QLabel *rr_ssx;
    QLabel *label_9;
    QLabel *rr_ssy;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *s_x;
    QSpinBox *s_y;
    QSpinBox *s_id;
    QComboBox *action;
    QLabel *s_resp;
    QLabel *label_13;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *gt_id;
    QLabel *gt_x;
    QLabel *gt_y;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *klient)
    {
        if (klient->objectName().isEmpty())
            klient->setObjectName(QString::fromUtf8("klient"));
        klient->resize(796, 379);
        centralWidget = new QWidget(klient);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        host = new QLineEdit(centralWidget);
        host->setObjectName(QString::fromUtf8("host"));
        host->setGeometry(QRect(30, 10, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        port = new QSpinBox(centralWidget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(60, 40, 42, 22));
        port->setMaximum(65535);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 46, 13));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 70, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 100, 75, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(180, 10, 151, 221));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 139, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        rr_lid = new QSpinBox(formLayoutWidget);
        rr_lid->setObjectName(QString::fromUtf8("rr_lid"));

        formLayout->setWidget(0, QFormLayout::FieldRole, rr_lid);

        rr_dia = new QSpinBox(formLayoutWidget);
        rr_dia->setObjectName(QString::fromUtf8("rr_dia"));

        formLayout->setWidget(1, QFormLayout::FieldRole, rr_dia);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        rr_id = new QLabel(formLayoutWidget);
        rr_id->setObjectName(QString::fromUtf8("rr_id"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rr_id);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        rr_ssx = new QLabel(formLayoutWidget);
        rr_ssx->setObjectName(QString::fromUtf8("rr_ssx"));

        formLayout->setWidget(3, QFormLayout::FieldRole, rr_ssx);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        rr_ssy = new QLabel(formLayoutWidget);
        rr_ssy->setObjectName(QString::fromUtf8("rr_ssy"));

        formLayout->setWidget(4, QFormLayout::FieldRole, rr_ssy);

        pushButton_3 = new QPushButton(formLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 10, 171, 221));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 20, 152, 181));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_11);

        s_x = new QSpinBox(formLayoutWidget_2);
        s_x->setObjectName(QString::fromUtf8("s_x"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, s_x);

        s_y = new QSpinBox(formLayoutWidget_2);
        s_y->setObjectName(QString::fromUtf8("s_y"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, s_y);

        s_id = new QSpinBox(formLayoutWidget_2);
        s_id->setObjectName(QString::fromUtf8("s_id"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, s_id);

        action = new QComboBox(formLayoutWidget_2);
        action->setObjectName(QString::fromUtf8("action"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, action);

        s_resp = new QLabel(formLayoutWidget_2);
        s_resp->setObjectName(QString::fromUtf8("s_resp"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, s_resp);

        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_13);

        pushButton_4 = new QPushButton(formLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, pushButton_4);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 10, 181, 221));
        formLayoutWidget_3 = new QWidget(groupBox_3);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 160, 181));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(formLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_12);

        label_14 = new QLabel(formLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_15);

        gt_id = new QLabel(formLayoutWidget_3);
        gt_id->setObjectName(QString::fromUtf8("gt_id"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, gt_id);

        gt_x = new QLabel(formLayoutWidget_3);
        gt_x->setObjectName(QString::fromUtf8("gt_x"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, gt_x);

        gt_y = new QLabel(formLayoutWidget_3);
        gt_y->setObjectName(QString::fromUtf8("gt_y"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, gt_y);

        klient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(klient);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 796, 21));
        klient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(klient);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        klient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(klient);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        klient->setStatusBar(statusBar);

        retranslateUi(klient);

        QMetaObject::connectSlotsByName(klient);
    } // setupUi

    void retranslateUi(QMainWindow *klient)
    {
        klient->setWindowTitle(QApplication::translate("klient", "klient", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("klient", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("klient", "Port", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("klient", "Po\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("klient", "Roz\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("klient", "Register Robot", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("klient", "LocalID", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("klient", "Diameter", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("klient", "ID", 0, QApplication::UnicodeUTF8));
        rr_id->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("klient", "SectorSizeX", 0, QApplication::UnicodeUTF8));
        rr_ssx->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("klient", "SectorSizeY", 0, QApplication::UnicodeUTF8));
        rr_ssy->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("klient", "PushButton", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("klient", "sector", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("klient", "ID", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("klient", "X", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("klient", "Y", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("klient", "Stan", 0, QApplication::UnicodeUTF8));
        action->clear();
        action->insertItems(0, QStringList()
         << QApplication::translate("klient", "Zajmij", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("klient", "Zwolnij", 0, QApplication::UnicodeUTF8)
        );
        s_resp->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("klient", "Odpowied\305\272", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("klient", "PushButton", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("klient", "GOTO", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("klient", "ID", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("klient", "X", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("klient", "Y", 0, QApplication::UnicodeUTF8));
        gt_id->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        gt_x->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
        gt_y->setText(QApplication::translate("klient", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class klient: public Ui_klient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KLIENT_H
