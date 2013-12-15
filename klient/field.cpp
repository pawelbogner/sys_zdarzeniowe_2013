#include "field.h"


Field::Field(int32_t xSize, int32_t ySize): _xSize(xSize), _ySize(ySize)
{

}

bool Field::informServerOfRobotLeaving(boost::shared_ptr<Robot> robotLeaving)
{
    // należy wysłać do serwera sygnał o zjeździe robota z pola




}

bool Field::robotDemandsFieldAccess(boost::shared_ptr<Robot> robotWishingToLeave, Field nextField)
{
    bool isFieldAccessGranted=nextField.reserve(); // pytanie o pozwolenie na wjazd na nextField
    if (isFieldAccessGranted) {
        // udzielono pozwolenia na wjazd na nextField
        // ustawienie potencjałów dla robota robotWishingToLeave
    }
    else {
        // nie udzielono pozwolenia
    }
    return false;
}

bool Field::reserve()
{
    // tu musimy pytać serwer o pozwolenie na wjazd na ten Field
}
