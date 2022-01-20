#include "LeakedObjectDetector.h"

struct Military;
struct Plane;

struct MilitaryTransport
{
    Military& newArmy;
    Plane& armyPlane;

    MilitaryTransport(Military& military_, Plane& plane_);
    ~MilitaryTransport();

    int getPassengers(const Military& newArmy);
    bool enoughSeats(const Military& newArmy, const Plane& armyPlane);
    JUCE_LEAK_DETECTOR(MilitaryTransport)
};
