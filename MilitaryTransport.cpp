#include "MilitaryTransport.h"

MilitaryTransport::MilitaryTransport()
{
    std::cout << "MilitaryTransport ctor" << std::endl;
}

int MilitaryTransport::getPassengers(const Military& army)
{
    return army.numSoldiers;
}

bool MilitaryTransport::enoughSeats(const Military& army, const Plane& plane)
{
    if(army.numSoldiers > plane.numSeats)
        return false;
    
    return true;
}