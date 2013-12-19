#ifndef QPROTOCOL_H
#define QPROTOCOL_H

#include <stdint.h>

typedef enum {eReserve = 1, eRelease = 0} eSectorRequest;
typedef enum {eAffirmative = 1, eNegative = 0} eSectorRequestResponse;

typedef struct
{
    int32_t type;
    int32_t length;
} tHeader;



typedef struct
{
    int32_t local_id;
    int32_t diameter;
} tRegisterRobot;

typedef struct
{
    tHeader header;
    tRegisterRobot data;
} tRegisterRobotSend;
#define REGISTER_ROBOT 1



typedef struct
{
    int32_t local_id;
    int32_t id;
    int32_t sector_size_x;
    int32_t sector_size_y;
    int32_t size_x;
    int32_t size_y;
} tRegisterRobotResponse;

typedef struct
{
    tHeader header;
    tRegisterRobotResponse data;
} tRegisterRobotResponseSend;
#define REGISTER_ROBOT_RESP 2





typedef struct
{
    int32_t id;
    int32_t x;
    int32_t y;
    eSectorRequest request;
} tRequestSector;

typedef struct
{
    tHeader header;
    tRequestSector data;
} tRequestSectorSend;
#define REQUEST_SECTOR 3





typedef struct
{
    int32_t id;
    int32_t x;
    int32_t y;
    eSectorRequestResponse response;
    int32_t clients;
} tResponseSector;

typedef struct
{
    tHeader header;
    tResponseSector data;
} tResponseSectorSend;
#define RESPONSE_SECTOR 4






typedef struct
{
    int32_t id;
    int32_t goto_x;
    int32_t goto_y;
} tGoToTask;

typedef struct
{
    tHeader header;
    tGoToTask data;
} tGoToTaskSend;
#define GOTO_TASK 5


typedef struct
{
    int32_t id;
    int32_t x;
    int32_t y;
} tCurrentPosition;

typedef struct
{
    tHeader header;
    tCurrentPosition data;
} tCurrentPositionSend;
#define CURRENT_POSITION 6




//typedef struct
//{

//}

#endif // QPROTOCOL_H

