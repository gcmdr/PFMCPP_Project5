struct StereoSystem;
struct Military;
struct Plane;
struct MilitaryTransport;
struct CargoShipment;

struct StereoWrapper 
{
    StereoWrapper(StereoSystem* stereo);
    ~StereoWrapper();

    StereoSystem* stPtr = nullptr;
};

struct MilitaryWrapper
{
    MilitaryWrapper(Military* military);
    ~MilitaryWrapper();

    Military* mtPtr = nullptr;
};

struct PlaneWrapper
{
    PlaneWrapper(Plane* plane);
    ~PlaneWrapper();

    Plane* plPtr = nullptr;
};

struct MilitaryTransportWrapper
{
    MilitaryTransportWrapper(MilitaryTransport* militaryTransport);
    ~MilitaryTransportWrapper();
    
    MilitaryTransport* mtTranPtr = nullptr;
};

struct CargoShipmentWrapper
{
    CargoShipmentWrapper(CargoShipment* cargoShipment);
    ~CargoShipmentWrapper();

    CargoShipment* cgPtr;
};
