#include <iostream>

struct Plane
{
    Plane();
    ~Plane()
    {
        std::cout << "Plane dtor" << std::endl;
    }
    int numSeats;
    std::string typeOfEngine;
    double cargoCapacity = 5000;
    double currentWeight = 0;
    float fuelLevel = 5000;
    
    void printDetailedMemberInfo();
    bool transportCargo(double parcelWeight);
    float sellAlcohol(int totalDrinks, float drinkPrice);
    void fly(int flightTime, float engineThrust, bool clearRunway = true);
    void cleanSeats(int numSeatsToClean);
    JUCE_LEAK_DETECTOR(Plane)
};