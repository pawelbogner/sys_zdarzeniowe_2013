#include "qclient.h"
#include "qprotocol.h"


QClient::QClient(QObject *parent) :
    QObject(parent)
{
    this->socket = new QTcpSocket(this);

    connect(this->socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ready_read()));
}

bool QClient::connect_to_host(QString host, qint16 port, int timeout)
{
    this->socket->connectToHost(host, port);

    return this->socket->waitForConnected(timeout);
}

void QClient::disconnect_from_host()
{
    this->socket->close();
}

void QClient::connected()
{
    this->_connected = true;
}

void QClient::disconnected()
{
    this->_connected = false;
}

void QClient::ready_read()
{
    tHeader header;

    this->socket->read((char*)&header, sizeof(header));

    switch(header.type)
    {
    case REGISTER_ROBOT_RESP:
    {
        tRegisterRobotResponse packet;
        socket->read((char*)&packet, sizeof(packet));

        emit register_robot_id(packet.local_id, packet.id, packet.sector_size_x, packet.sector_size_y, packet.size_x, packet.size_y);
    }
        break;
    case RESPONSE_SECTOR:
    {
        tResponseSector packet;
        socket->read((char*)&packet, sizeof(packet));

        emit response_sector(packet.id, packet.x, packet.y, packet.response, packet.clients);
    }
        break;
    case GOTO_TASK:
    {
        tGoToTask packet;
        socket->read((char*)&packet, sizeof(packet));

        emit go_to(packet.id, packet.goto_x, packet.goto_y);

    }
        break;

    }
}

void QClient::register_robot(int32_t local_id, int32_t diameter)
{
    tRegisterRobotSend response;
    response.header.type = REGISTER_ROBOT;
    response.header.length = sizeof(response.data);

    response.data.local_id = local_id;
    response.data.diameter = diameter;

    socket->write((char*)&response, sizeof(response));
    socket->flush();
}

void QClient::request_sector(int32_t id, int32_t x, int32_t y, eSectorRequest request)
{
    tRequestSectorSend response;
    response.header.type = REQUEST_SECTOR;
    response.header.length = sizeof(response.data);

    response.data.id = id;
    response.data.x = x;
    response.data.y = y;
    response.data.request = request;

    socket->write((char*)&response, sizeof(response));
    socket->flush();
}

void QClient::current_position(int32_t id, int32_t x, int32_t y)
{
    tCurrentPositionSend response;
    response.header.type = CURRENT_POSITION;
    response.header.length = sizeof(response.data);

    response.data.id = id;
    response.data.x = x;
    response.data.y = y;

    socket->write((char*)&response, sizeof(response));
    socket->flush();

}

