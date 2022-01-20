#include "Wrappers.h"

#include "StereoSystem.h"
#include "Plane.h"
#include "CargoShipment.h"
#include "Military.h"
#include "MilitaryTransport.h"

StereoWrapper::StereoWrapper(StereoSystem* stereo) : stPtr(stereo) {}
StereoWrapper::~StereoWrapper()
{
    delete stPtr;
}

MilitaryWrapper::MilitaryWrapper(Military* military) : 
    mtPtr(military) {}

MilitaryWrapper::~MilitaryWrapper()
{
    delete mtPtr;
}

PlaneWrapper::PlaneWrapper(Plane* plane) : 
    plPtr(plane) {}

PlaneWrapper::~PlaneWrapper()
{
    delete plPtr;
}

MilitaryTransportWrapper::MilitaryTransportWrapper(MilitaryTransport* militaryTransport) : 
    mtTranPtr(militaryTransport) {}

MilitaryTransportWrapper::~MilitaryTransportWrapper()
{
    delete mtTranPtr;
}

CargoShipmentWrapper::CargoShipmentWrapper(CargoShipment* cargoShipment) : 
    cgPtr(cargoShipment) {}
CargoShipmentWrapper::~CargoShipmentWrapper()
{
    delete cgPtr;
}