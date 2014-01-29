#include "qserwer.h"
#include "qprotocol.h"
#include <QtNetwork>
#include <iostream>

QSerwer::QSerwer(uint32_t sector_size_x, uint32_t sector_size_y, uint32_t size_x, uint32_t size_y, QObject *parent) :
    QObject(parent)
{
    this->last_id = 0;
    this->sector_size_x = sector_size_x;
    this->sector_size_y = sector_size_y;
    this->size_x = size_x;
    this->size_y = size_y;

    this->server = new QTcpServer(this);

    connect(this->server, SIGNAL(newConnection()), this, SLOT(NewConnection()));

    this->signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(QObject*)),
            this, SLOT(ReadData(QObject*)));
    std::cerr << "Constructed." << std::endl;
}

bool QSerwer::StartServer(quint16 port)
{
    std::cerr << "Server started." << std::endl;
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
    return this->server->listen(QHostAddress::Any, port);
}

void QSerwer::StopServer()
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
    this->server->close();

}

void QSerwer::NewConnection()
{
    QTcpSocket *clientConnection = this->server->nextPendingConnection();

    this->list_of_connections.push_back(clientConnection);

    connect(clientConnection, SIGNAL(readyRead()), this->signalMapper, SLOT(map()));
    this->signalMapper->setMapping(clientConnection, clientConnection);

    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    std::cerr << __PRETTY_FUNCTION__ << std::endl;

}

void QSerwer::ReadData(QObject *s)
{
    QTcpSocket *socket = (QTcpSocket*)(s);

    tHeader header;

    socket->read((char*)&header, sizeof(header));
    std::cerr << "received: ";
    std::cerr << header.type << ", " << header.length;

    switch(header.type)
    {
    case REGISTER_ROBOT:
    {
        tRegisterRobot packet;
        tRegisterRobotResponseSend response;
        tRobot r;

        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.local_id << ", " << packet.diameter << "." << std::endl;

        this->last_id++;

        response.header.type = REGISTER_ROBOT_RESP;
        response.header.length = sizeof(response.data);

        response.data.id = this->last_id;
        response.data.local_id = packet.local_id;
        response.data.sector_size_x = this->sector_size_x;
        response.data.sector_size_y = this->sector_size_y;
        response.data.size_x = this->size_x;
        response.data.size_y = this->size_y;


        r.id = response.data.id;
        r.connection = socket;
        this->list_of_robots.push_back(r);

        socket->write((char*)&response, sizeof(response));
        socket->flush();

        emit register_robot(response.data.id, packet.diameter);
    }
        break;
    case REQUEST_SECTOR:
    {
        tRequestSector packet;
        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.id << ", " << packet.x << ", " << packet.y << ", " << packet.request << "." << std::endl;

        emit request_sector(packet.id, packet.x, packet.y, packet.request);
    }
        break;
    case CURRENT_POSITION:
    {
        tCurrentPosition packet;
        socket->read((char*)&packet, sizeof(packet));
        socket->flush();
        std::cerr << "; data: ";
        std::cerr << packet.id << ", " << packet.x << ", " << packet.y << "." << std::endl;


        emit current_position(packet.id, packet.x, packet.y);
    }
        break;

    }
    socket->flush();
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
}

void QSerwer::response_sector(int32_t id, int32_t x, int32_t y, int32_t resp, int32_t clients, int32_t goto_x, int32_t goto_y)
{
    tResponseSectorSend response;
    QTcpSocket *socket;
    response.header.type = RESPONSE_SECTOR;
    response.header.length = sizeof(response.data);

    response.data.id = id;
    response.data.x = x;
    response.data.y = y;
    response.data.response = static_cast<eSectorRequestResponse>(resp);
    response.data.clients = clients;
    response.data.goto_x=goto_x;
    response.data.goto_y=goto_y;

    socket = 0;
    for (int i = 0; i < this->list_of_robots.size(); i++)
    {
        if (this->list_of_robots.at(i).id == id)
        {
            socket = this->list_of_robots.at(i).connection;
            socket->write((char*)&response, sizeof(response));
            socket->flush();
            break;
        }
    }
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
}

