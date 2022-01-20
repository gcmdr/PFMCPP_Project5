struct StereoSystem;
struct Plane;

struct CargoShipment
{
    CargoShipment(StereoSystem& stl, Plane& musicPlane);
    ~CargoShipment();
    
    StereoSystem* st1 = nullptr;
    Plane* musicPlane = nullptr;

    void getStereoInfo(const StereoSystem* st1);
    bool readyForFlight(const Plane* musicPlane);
    JUCE_LEAK_DETECTOR(CargoShipment)
};