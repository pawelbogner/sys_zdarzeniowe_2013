#ifndef QSERWER_H
#define QSERWER_H

#include <QObject>
#include "qreader.h"

#include <QtNetwork>

#include <QSignalMapper>
#include <QVector>

#include "qprotocol.h"

typedef struct
{
    int32_t id;
    QTcpSocket* connection;
} tRobot;

class QSerwer : public QObject
{
    Q_OBJECT
public:
    // parametry sector_size_x i sector_size_y zawierają rozmiary sektora w jednostkach mapy
    //
    explicit QSerwer(uint32_t sector_size_x, uint32_t sector_size_y, uint32_t size_x, uint32_t size_y, QObject *parent = 0);

    uint8_t responseBF;
public slots:
    bool StartServer(quint16 port);
    void StopServer();

    // funkcja odpowiada na żądanie zajęcia sektora.
    // x, y to numery sektora,
    // response określa czy można wjechać na sektor wartości eAffirmative = 1, eNegative = 0
    // clients określa ile klientów jest w sektorze
    void response_sector(int32_t id, int32_t x, int32_t y, int32_t response, int32_t clients, int32_t goto_x, int32_t goto_y);

    // zlecenie zadania przejazdu do punktu x, y w jednostkach mapy


private slots:
    void NewConnection();

    void ReadData(QObject* s);
    
private:
    QTcpServer *server;
    QReader *reader;
    QNetworkSession *ns;

    QSignalMapper *signalMapper;

    QVector<QTcpSocket*> list_of_connections;

    QVector<tRobot> list_of_robots;
    int32_t last_id;

    uint32_t sector_size_x;
    uint32_t sector_size_y;
    uint32_t size_x;
    uint32_t size_y;

signals:
    // rejestruje robota. diameter jest średnicą robota w jednostkach mapy
    void register_robot  (int32_t robot_id, int32_t diameter);

    // prośba o zajęcie sektora. x, y to identyfikatory sektorów, request określa czy zwalniamy sektor czy zajmujemy
    // w przypadku zwalniania sektora nie ma potrzeby odpowiadać.
    // w przypadku zajmowania należy odpowiedzieć używając slotu response_sector
    // request przyjmuje wartości eReserve = 1, eRelease = 0
    void request_sector  (int32_t robot_id, int32_t x, int32_t y, eSectorRequest request);

    // informacja o położeniu środka robota w jednostkach mapy
    void current_position(int32_t robot_id, int32_t x, int32_t y);
};

#endif // QSERWER_H
