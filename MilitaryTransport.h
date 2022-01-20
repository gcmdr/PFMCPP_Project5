

struct MilitaryTransport
{
    MilitaryTransport();
    ~MilitaryTransport()
    {
        std::cout << "MilitaryTransport dtor" << std::endl;
        newArmy.defend(127);
    }

    Military newArmy;
    Plane armyPlane;

    int getPassengers(const Military& newArmy);
    bool enoughSeats(const Military& newArmy, const Plane& armyPlane);
    JUCE_LEAK_DETECTOR(MilitaryTransport)
};