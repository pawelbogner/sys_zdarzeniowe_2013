#ifndef SERWERMAIN_H
#define SERWERMAIN_H

#include <QWidget>

#include "qserwer.h"

namespace Ui {
class SerwerMain;
}

class SerwerMain : public QWidget
{
    Q_OBJECT
    
public:
    explicit SerwerMain(QWidget *parent = 0);
    ~SerwerMain();
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_se_resp_valueChanged(int arg1);

private:
    Ui::SerwerMain *ui;

    QSerwer *serwer;
};

#endif // SERWERMAIN_H
