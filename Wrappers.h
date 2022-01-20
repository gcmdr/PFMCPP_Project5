

struct StereoWrapper 
{
    StereoWrapper(StereoSystem* stereo) : stPtr(stereo) {}
    ~StereoWrapper()
    {
        delete stPtr;
    }

    StereoSystem* stPtr = nullptr;
};

struct MilitaryWrapper
{
    MilitaryWrapper(Military* military) : mtPtr(military) {}
    ~MilitaryWrapper()
    {
        delete mtPtr;
    }

    Military* mtPtr = nullptr;
};

struct PlaneWrapper
{
    PlaneWrapper(Plane* plane) : plPtr(plane) {}
    ~PlaneWrapper()
    {
        delete plPtr;
    }

    Plane* plPtr = nullptr;
};

struct MilitaryTransportWrapper
{
    MilitaryTransportWrapper(MilitaryTransport* militaryTransport) : mtTranPtr(militaryTransport) {}
    ~MilitaryTransportWrapper()
    {
        delete mtTranPtr;
    }

    MilitaryTransport* mtTranPtr = nullptr;
};

struct CargoShipmentWrapper
{
    CargoShipmentWrapper(CargoShipment* cargoShipment) : cgPtr(cargoShipment) {}
    ~CargoShipmentWrapper()
    {
        delete cgPtr;
    }

    CargoShipment* cgPtr;
};