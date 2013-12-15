/********************************************************************************
** Form generated from reading UI file 'serwermain.ui'
**
** Created: Sun Dec 15 21:08:54 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERWERMAIN_H
#define UI_SERWERMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerwerMain
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *lablel1;
    QSpinBox *gt_id;
    QLabel *xLabel;
    QLabel *yLabel;
    QSpinBox *gt_x;
    QSpinBox *gt_y;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *idLabel;
    QSpinBox *se_id;
    QLabel *xLabel_2;
    QSpinBox *se_x;
    QLabel *yLabel_2;
    QSpinBox *se_y;
    QLabel *respLabel;
    QLabel *cliLabel;
    QPushButton *pushButton_4;
    QSpinBox *se_cli;
    QSpinBox *se_resp;

    void setupUi(QWidget *SerwerMain)
    {
        if (SerwerMain->objectName().isEmpty())
            SerwerMain->setObjectName(QString::fromUtf8("SerwerMain"));
        SerwerMain->resize(908, 364);
        groupBox = new QGroupBox(SerwerMain);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 201, 141));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 160, 95));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(65535);
        spinBox->setValue(91);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton);

        pushButton_2 = new QPushButton(formLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_2);

        groupBox_2 = new QGroupBox(SerwerMain);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 20, 211, 211));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 20, 191, 181));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        lablel1 = new QLabel(formLayoutWidget_2);
        lablel1->setObjectName(QString::fromUtf8("lablel1"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lablel1);

        gt_id = new QSpinBox(formLayoutWidget_2);
        gt_id->setObjectName(QString::fromUtf8("gt_id"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, gt_id);

        xLabel = new QLabel(formLayoutWidget_2);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, xLabel);

        yLabel = new QLabel(formLayoutWidget_2);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, yLabel);

        gt_x = new QSpinBox(formLayoutWidget_2);
        gt_x->setObjectName(QString::fromUtf8("gt_x"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, gt_x);

        gt_y = new QSpinBox(formLayoutWidget_2);
        gt_y->setObjectName(QString::fromUtf8("gt_y"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, gt_y);

        pushButton_3 = new QPushButton(formLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, pushButton_3);

        groupBox_3 = new QGroupBox(SerwerMain);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(460, 20, 251, 211));
        formLayoutWidget_3 = new QWidget(groupBox_3);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 231, 194));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(formLayoutWidget_3);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, idLabel);

        se_id = new QSpinBox(formLayoutWidget_3);
        se_id->setObjectName(QString::fromUtf8("se_id"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, se_id);

        xLabel_2 = new QLabel(formLayoutWidget_3);
        xLabel_2->setObjectName(QString::fromUtf8("xLabel_2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, xLabel_2);

        se_x = new QSpinBox(formLayoutWidget_3);
        se_x->setObjectName(QString::fromUtf8("se_x"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, se_x);

        yLabel_2 = new QLabel(formLayoutWidget_3);
        yLabel_2->setObjectName(QString::fromUtf8("yLabel_2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, yLabel_2);

        se_y = new QSpinBox(formLayoutWidget_3);
        se_y->setObjectName(QString::fromUtf8("se_y"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, se_y);

        respLabel = new QLabel(formLayoutWidget_3);
        respLabel->setObjectName(QString::fromUtf8("respLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, respLabel);

        cliLabel = new QLabel(formLayoutWidget_3);
        cliLabel->setObjectName(QString::fromUtf8("cliLabel"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, cliLabel);

        pushButton_4 = new QPushButton(formLayoutWidget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, pushButton_4);

        se_cli = new QSpinBox(formLayoutWidget_3);
        se_cli->setObjectName(QString::fromUtf8("se_cli"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, se_cli);

        se_resp = new QSpinBox(formLayoutWidget_3);
        se_resp->setObjectName(QString::fromUtf8("se_resp"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, se_resp);


        retranslateUi(SerwerMain);

        QMetaObject::connectSlotsByName(SerwerMain);
    } // setupUi

    void retranslateUi(QWidget *SerwerMain)
    {
        SerwerMain->setWindowTitle(QApplication::translate("SerwerMain", "SerwerMain", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SerwerMain", "GroupBox", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SerwerMain", "Port", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SerwerMain", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SerwerMain", "Stop", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SerwerMain", "goto", 0, QApplication::UnicodeUTF8));
        lablel1->setText(QApplication::translate("SerwerMain", "id", 0, QApplication::UnicodeUTF8));
        xLabel->setText(QApplication::translate("SerwerMain", "x", 0, QApplication::UnicodeUTF8));
        yLabel->setText(QApplication::translate("SerwerMain", "y", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SerwerMain", "go", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SerwerMain", "sector", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("SerwerMain", "id", 0, QApplication::UnicodeUTF8));
        xLabel_2->setText(QApplication::translate("SerwerMain", "x", 0, QApplication::UnicodeUTF8));
        yLabel_2->setText(QApplication::translate("SerwerMain", "y", 0, QApplication::UnicodeUTF8));
        respLabel->setText(QApplication::translate("SerwerMain", "resp", 0, QApplication::UnicodeUTF8));
        cliLabel->setText(QApplication::translate("SerwerMain", "#cli", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("SerwerMain", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SerwerMain: public Ui_SerwerMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERWERMAIN_H
