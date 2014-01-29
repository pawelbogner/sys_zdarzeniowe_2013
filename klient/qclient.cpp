#include "qclient.h"
#include "qprotocol.h"
#include <iostream>

QClient::QClient(QObject *parent) :
    QObject(parent)
{
    this->socket = new QTcpSocket(this);

    connect(this->socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(ready_read()));

    _localId=0;
}

bool QClient::connect_to_host(QString host, qint16 port, int timeout)
{
    this->socket->connectToHost(host, port);
    std::cerr<<"polaczono"<<std::endl;
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
    std::cerr << "received: ";
    std::cerr << header.type << ", " << header.length;

    switch(header.type)
    {
    case REGISTER_ROBOT_RESP:
    {
        tRegisterRobotResponse packet;
        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.local_id << ", " << packet.id << ", " << packet.sector_size_x << ", " << packet.sector_size_y << ", " << packet.size_x << ", " << packet.size_y << "." << std::endl;

        emit register_robot_id(packet.local_id, packet.id, _currentRobotStartingX, _currentRobotStartingY, packet.sector_size_x, packet.sector_size_y, packet.size_x, packet.size_y);
    }
        break;
    case RESPONSE_SECTOR:
    {
        tResponseSector packet;
        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.id << ", " << packet.x << ", " << packet.y << ", " << packet.response << ", " << packet.clients << ", " << packet.goto_x << ", " << packet.goto_y << "." << std::endl;

        emit go_to(packet.id, packet.goto_x, packet.goto_y);
        emit response_sector(packet.id, packet.x, packet.y, packet.response, packet.clients);
    }
        break;
    /*case GOTO_TASK:
    {
        tGoToTask packet;
        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.id << ", " << packet.goto_x << ", " << packet.goto_y << "." << std::endl;

        emit go_to(packet.id, packet.goto_x, packet.goto_y);

    }
        break;*/

    }
    socket->flush();
}

void QClient::register_robot(int32_t startingX, int32_t startingY, int32_t diameter)
{
    tRegisterRobotSend response;
    response.header.type = REGISTER_ROBOT;
    response.header.length = sizeof(response.data);

    response.data.local_id = ++_localId;
    response.data.diameter = diameter;

    _currentRobotStartingX=startingX;
    _currentRobotStartingY=startingY;

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

