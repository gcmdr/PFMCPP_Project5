#include "Plane.h"

Plane::Plane() :
numSeats(240),
typeOfEngine("turboprop")
{
    std::cout << "Plane ctor" << std::endl;
}

Plane::~Plane()
{
    std::cout << "Plane dtor" << std::endl;
}

void Plane::printDetailedMemberInfo()
{
    std::cout << "pl1 typeOfEngine: " << this->typeOfEngine << " and pl1 cargoCapacity: " << this->cargoCapacity << std::endl; 
}

bool Plane::transportCargo(double parcelWeight)
{
    std::cout << "Cargo capacity is: " << cargoCapacity << std::endl;
    if(currentWeight + parcelWeight > cargoCapacity)
         return false;
        
    currentWeight += parcelWeight;
    return true;
        
}

void Plane::cleanSeats(int numberOfSeats)
{
    int numCleanedSeats = 0;
    for(int i = 0; i < numberOfSeats; ++i)
    {
        ++numCleanedSeats;
    }
    std::cout << numCleanedSeats << " seats cleaned" << std::endl;

}

float Plane::sellAlcohol(int totalDrinks, float drinkPrice)
{
    float alcoholSales = totalDrinks * drinkPrice;
    std::cout << "Plane::sellAlcohol  alcoholSales = " << alcoholSales << std::endl; 
    return alcoholSales;
}

void Plane::fly(int flightTime, float engineThrust, bool clearRunway)
{
    std::cout << "Type of engine: " << typeOfEngine << std::endl; 
    if (clearRunway)
    {
        std::cout << "Plane::sellAlcohol  Runyway is Clear " << std::endl; 
        fuelLevel -= (flightTime * engineThrust);
    }
}
