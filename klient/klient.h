#ifndef KLIENT_H
#define KLIENT_H

#include <QMainWindow>
#include "qclient.h"

namespace Ui {
class klient;
}

class klient : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit klient(QWidget *parent = 0);
    ~klient();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void register_robot_id(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y);
    void response_sector  (int32_t id, int32_t x, int32_t y, eSectorRequestResponse response, int32_t clients);
    void go_to            (int32_t id, int32_t goto_x, int32_t goto_y);

private:
    Ui::klient *ui;
    QClient *client;
};

#endif // KLIENT_H
