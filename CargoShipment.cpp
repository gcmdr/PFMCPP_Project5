#include "CargoShipment.h"
#include "Plane.h"
#include "StereoSystem.h"
#include <iostream>


CargoShipment::CargoShipment(StereoSystem& st_, Plane& plane_) :
    st1(&st_),
    musicPlane(&plane_)
{
    
    std::cout << "CargoShipment ctor" << std::endl;
}

CargoShipment::~CargoShipment()
    {
        st1->destroyTheBass();
        std::cout << "CargoShipment dtor" << std::endl;
    }

void CargoShipment::getStereoInfo(const StereoSystem* stereo)
{
    std::cout << "numSpeakers: " << stereo->numSpeakers << std::endl;
    std::cout << "wattsOfPower = " << stereo->wattsOfPower << std::endl;
    std::cout << "numAnalogInputs = " << stereo->numAnalogInputs << std::endl;
    std::cout << "numDigitalInputs = " << stereo->numDigitalInputs << std::endl;
} 

bool CargoShipment::readyForFlight(const Plane* plane)
{
    if (plane->fuelLevel > 3000.0f)
        return true;

    return false;
}