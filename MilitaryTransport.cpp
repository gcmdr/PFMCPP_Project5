#include "MilitaryTransport.h"
#include "Military.h"
#include "Plane.h"

MilitaryTransport::MilitaryTransport(Military& military_, Plane& plane_) :
    newArmy(military_),
    armyPlane(plane_)
    
{
    std::cout << "MilitaryTransport ctor" << std::endl;
}

MilitaryTransport::~MilitaryTransport()
{
    std::cout << "MilitaryTransport dtor" << std::endl;
    newArmy.defend(127);
}

int MilitaryTransport::getPassengers(const Military& army)
{
    return army.numSoldiers;
}

bool MilitaryTransport::enoughSeats(const Military& army, const Plane& plane)
{
    return army.numSoldiers > plane.numSeats;
}
