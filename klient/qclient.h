#ifndef QCLIENT_H
#define QCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "qprotocol.h"

class QClient : public QObject
{
    Q_OBJECT
public:
    explicit QClient(QObject *parent = 0);
    bool connect_to_host(QString host, qint16 port, int timeout);
    void disconnect_from_host();
private:
    QTcpSocket *socket;
    bool _connected;

signals:
    void register_robot_id(int32_t local_id, int32_t id, int32_t sector_size_x, int32_t sector_size_y, int32_t size_x, int32_t size_y);
    void response_sector  (int32_t id, int32_t x, int32_t y, eSectorRequestResponse response, int32_t clients);
    void go_to            (int32_t id, int32_t goto_x, int32_t goto_y);
private slots:
    void connected();
    void disconnected();
    void ready_read();

public slots:
    void register_robot(int32_t local_id, int32_t diameter);
    void request_sector(int32_t id, int32_t x, int32_t y, eSectorRequest request);
    void current_position(int32_t id, int32_t x, int32_t y);
    
};

#endif // QCLIENT_H

