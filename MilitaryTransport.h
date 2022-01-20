#include <iostream>

struct Military;
struct Plane;

struct MilitaryTransport
{
    MilitaryTransport(Military& military_, Plane& plane_);
    ~MilitaryTransport();

    Military* newArmy;
    Plane* armyPlane;

    int getPassengers(const Military* newArmy);
    bool enoughSeats(const Military* newArmy, const Plane* armyPlane);
    JUCE_LEAK_DETECTOR(MilitaryTransport)
};