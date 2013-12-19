#include "field.h"
#include "qprotocol.h"


Field::Field(int32_t xSize, int32_t ySize, int32_t xCoord, int32_t yCoord):
    _xSize(xSize), _ySize(ySize), _xCoord(xCoord), _yCoord(yCoord)
{

}

bool Field::informServerOfRobotLeaving(boost::shared_ptr<Robot> robotLeaving, Field nextField)
{
    // należy wysłać do serwera sygnał o zjeździe robota z pola


    // robot wjeżdża do nextField
    nextField.addRobot(robotLeaving);
    removeRobot(robotLeaving);
}

bool Field::robotDemandsFieldAccess(boost::shared_ptr<Robot> robotWishingToLeave, Field nextField)
{
    bool isFieldAccessGranted=nextField.reserve(robotWishingToLeave); // pytanie o pozwolenie na wjazd na nextField
    if (isFieldAccessGranted) {
        // udzielono pozwolenia na wjazd na nextField
        // ustawienie potencjałów dla robota robotWishingToLeave
    }
    else {
        // nie udzielono pozwolenia
    }
    return false;
}

bool Field::reserve(boost::shared_ptr<Robot> robotWishingToEnter)
{
    // tu musimy pytać serwer o pozwolenie na wjazd na ten Field
    _client->request_sector(robotWishingToEnter->getLocalId(), _xCoord, _yCoord, eReserve);

}

void Field::removeRobot(boost::shared_ptr<Robot> robot)
{

}

void Field::addRobot(boost::shared_ptr<Robot> robot)
{

}

void Field::computeOneIterationOfMotion()
{

}

