#pragma once
#include "LeakedObjectDetector.h"

struct StereoSystem;
struct Plane;

struct CargoShipment
{
    CargoShipment(StereoSystem& st_, Plane& plane_);
    ~CargoShipment();
    
    StereoSystem& st1;
    Plane& musicPlane;

    void getStereoInfo(const StereoSystem& st1);
    bool readyForFlight(const Plane& musicPlane);
    JUCE_LEAK_DETECTOR(CargoShipment)
};
