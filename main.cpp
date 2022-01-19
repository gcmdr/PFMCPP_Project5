/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */





/*
 copied UDT 1:
 */


struct StereoWrapper 
{
    StereoWrapper(StereoSystem* stereo) : stPtr(stereo) {}
    ~StereoWrapper()
    {
        delete stPtr;
    }

    StereoSystem* stPtr = nullptr;
};
    
StereoSystem::StereoSystem() : 
numEQBands(5),
subOn(false),
maxBassLevel(10),
bassLevel(0)
{
    std::cout << "StereoSystem ctor" << std::endl;
}

StereoSystem::Tape::Tape() : 
quality(1.0f),
minPerSide(30),
positionInMinutes(0)
{
    std::cout << "StereoSystem::Tape ctor" << std::endl;
}

void StereoSystem::printDetailedMemberInfo()
{
    std::cout << "st1 numAnalogInputs: " << this->numAnalogInputs << " and st1 numDigitalInputs: " << this->numDigitalInputs << std::endl; 
}       

void StereoSystem::playMusic(std::string album, int track)
{
    std::cout << "Max bass level = " << maxBassLevel << std::endl;
    std::cout << "Now Playing: " << album << ", Track " << track << std::endl; 
}

void StereoSystem::boostBass(int bassBoostAmount)
{
    if(subOn) 
        bassBoostAmount += 5;

    if(bassLevel + bassBoostAmount > maxBassLevel) 
        bassLevel = maxBassLevel;
    else 
        bassLevel += bassBoostAmount;
    std::cout << "Watts of power = " << wattsOfPower << std::endl; 
    std::cout << "StereoSystem::boostBass  basslevel = " << bassLevel << std::endl; 
}

void StereoSystem::destroyTheBass()
{
    while(bassLevel > 0)
    {
        --bassLevel;
    }
    std::cout << "Bass has been destroyed, bass level is now: " << bassLevel << std::endl;
}

StereoSystem::Tape StereoSystem::dubTapes(Tape& tape1)
{
    tape1.quality *= 0.9f;
    tape1.tapeName += " dub";
    std::cout << "StereoSystem::Tape  tapeQuality = " << tape1.quality << std::endl; 
    return tape1;
}

void StereoSystem::Tape::printDetailedMemberInfo()
{
    std::cout << "tp1 type: " << this->type << " and tp1 getTitle(): " << this->getTitle() << std::endl; 
}

void StereoSystem::Tape::rewind(bool beginning, int lengthOfTime)
{
    if(beginning) 
    {
        positionInMinutes = 0;
    }
    else 
    {
        if(positionInMinutes - lengthOfTime <= 0) 
            positionInMinutes = 0;
        else 
            positionInMinutes -= lengthOfTime;
    }
    std::cout << "Position in minutes = " << positionInMinutes << std::endl;
}
        
void StereoSystem::Tape::fastForward(bool end, int lengthOfTime)
{
    if(end) 
    {
        positionInMinutes = minPerSide;
    }
    else 
    {
        if (positionInMinutes + lengthOfTime >= minPerSide) 
            positionInMinutes = minPerSide;
        else 
            positionInMinutes += lengthOfTime;
    }
    std::cout << "StereoSystem::Tape::FastForward  positionInMinutes = " << positionInMinutes << std::endl; 
}

std::string StereoSystem::Tape::getTitle()
{
    return tapeName;
}

void StereoSystem::Tape::splice(int lengthOfSplice)
{
    int i = 0;
    while(i < lengthOfSplice)
    {
        ++minPerSide;
        ++i;
    }
    std::cout << "After splice,min per side = " << minPerSide << std::endl;
}
/*
 copied UDT 2:
 */
struct Military
{
    Military();
    ~Military()
    {
        std::cout << "Military dtor" << std::endl;
    }
    std::string branchOfMilitary;
    int numBases;
    int numSoldiers = 5000;
    float budget = 10000000.0f;
    int numReserveSoldiers = 1000;

    struct Soldier
    {
        Soldier();
        ~Soldier()
        {
            std::cout << "Soldier dtor" << std::endl;
        }
        float height = 60.2f;
        float weight;
        std::string mainSkill;
        int yearsExperience;
        std::string rank = "corporal";

        void printDetailedMemberInfo();
        bool readyForCombat(float requiredWeight, int requiredExperience);
        void constructShelter(int numberOfSoldiers, std::string weatherConditions = "cloudy");
        void skillsAndRank(std::string mainSkill, std::string rank);
        float weightGainFromPushups(int numberOfPushups);
        
    };

    void printDetailedMemberInfo();
    float spendMoney(std::string Contract, float budget=10000000.57f);
    void defend(int numEnemySoldiers);
    bool invade(int numEnemySoldiers, int numEnemyBases);
    int catch22(int numBombs);

    Soldier soldier1;
    JUCE_LEAK_DETECTOR(Military)
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

Military::Military() : 
branchOfMilitary("Navy"),
numBases(127)
{
    std::cout << "Military ctor" << std::endl;
}

Military::Soldier::Soldier() :
weight(185.0f),
mainSkill("munitions"),
yearsExperience(5)
{
    std::cout << "Military::Soldier ctor" << std::endl;
}

void Military::printDetailedMemberInfo()
{
    std::cout << "mt numBases: " << this->numBases << " and mt numSoldiers: " <<this->numSoldiers << std::endl; 
}

float Military::spendMoney (std::string Contract, float expense)
{
    std::cout << "Budget = " << budget << std::endl;
    if(expense > budget) 
    {
        std::cout << "Not enough money to fulfill contract." << std::endl;
        return budget;
    }

    std::cout << "Contract " << Contract << " approved." << std::endl;
    return budget - expense;
}
    
void Military::defend (int numEnemySoldiers)
{
    std::cout << "Military::defend" << std::endl;
    if(numEnemySoldiers > numSoldiers)
    {
        int callUpSoldiers = (numEnemySoldiers - numSoldiers) + 100;
        
        if (callUpSoldiers > numReserveSoldiers) 
            callUpSoldiers = numReserveSoldiers;
        else 
            numReserveSoldiers -= callUpSoldiers; 

        numSoldiers += callUpSoldiers;
        std::cout << "Military::defend  numSoldiers = " << numSoldiers << std::endl; 
        std::cout << "numBases = " << numBases << std::endl; 
    }
}

bool Military::invade (int numEnemySoldiers, int numEnemyBases)
{
    if(numEnemyBases > numBases || numEnemySoldiers > numSoldiers) 
        return false;
    
    return true;
}

bool Military::Soldier::readyForCombat(float requiredWeight, int requiredExperience)
{
    if (weight > requiredWeight || yearsExperience < requiredExperience) 
        return false;
    
    return true;
}

int Military::catch22(int bombs)
{
    int basesDestroyed = 0;
    while(bombs > 0)
    {
        ++basesDestroyed;
        --bombs;
    }
    std::cout << basesDestroyed << " bases have been destroyed" << std::endl;
    return basesDestroyed;
}

void Military::Soldier::printDetailedMemberInfo()
{
    std::cout << "soldier mainSkill: " << this->mainSkill << " and soldier yearsExperience: " << this->yearsExperience << std::endl; 
}

void Military::Soldier::constructShelter(int numberOfSoldiers, std::string weatherConditions)
{
    std::cout << "Construct shelter for: " << numberOfSoldiers <<  " soldiers." << std::endl;
    std::cout << "Weather conditions: " << weatherConditions << std::endl;
}

void Military::Soldier::skillsAndRank(std::string primarySkill, std::string currentRank)
{
    std::cout << "Rank: " << currentRank << std::endl; 
    std::cout << "Skill: " << primarySkill << std::endl;
    std::cout << "Main Skill: " << mainSkill << std::endl;
}

float Military::Soldier::weightGainFromPushups(int numPushups)
{
    float weightGained = 0.0f;
    for (int i = 1; i < numPushups; ++i)
    {
        if(i % 5 == 0)
        {
            weightGained += .01f;
        }
    }

    weight += weightGained; // add weightGained to total weight
    std::cout << weightGained << "lbs were gained!" << std::endl;
    return weightGained;
}
/*
 copied UDT 3:
 */
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

struct PlaneWrapper
{
    PlaneWrapper(Plane* plane) : plPtr(plane) {}
    ~PlaneWrapper()
    {
        delete plPtr;
    }

    Plane* plPtr = nullptr;
};


Plane::Plane() :
numSeats(240),
typeOfEngine("turboprop")
{
    std::cout << "Plane ctor" << std::endl;
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
/*
 new UDT 4:
 with 2 member functions
 */
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

struct MilitaryTransportWrapper
{
    MilitaryTransportWrapper(MilitaryTransport* militaryTransport) : mtTranPtr(militaryTransport) {}
    ~MilitaryTransportWrapper()
    {
        delete mtTranPtr;
    }

    MilitaryTransport* mtTranPtr = nullptr;
};

MilitaryTransport::MilitaryTransport()
{
    std::cout << "MilitaryTransport ctor" << std::endl;
}

int MilitaryTransport::getPassengers(const Military& army)
{
    return army.numSoldiers;
}

bool MilitaryTransport::enoughSeats(const Military& army, const Plane& plane)
{
    if(army.numSoldiers > plane.numSeats)
        return false;
    
    return true;
}
/*
 new UDT 5:
 with 2 member functions
 */
struct CargoShipment
{
    CargoShipment();
    ~CargoShipment()
    {
        st1.destroyTheBass();
        std::cout << "CargoShipment dtor" << std::endl;
    }

    StereoSystem st1;
    Plane musicPlane;

    void getStereoInfo(const StereoSystem& st1);
    bool readyForFlight(const Plane& musicPlane);
    JUCE_LEAK_DETECTOR(CargoShipment)
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

CargoShipment::CargoShipment()
{
    std::cout << "CargoShipment ctor" << std::endl;
}

void CargoShipment::getStereoInfo(const StereoSystem& stereo)
{
    std::cout << "numSpeakers: " << stereo.numSpeakers << std::endl;
    std::cout << "wattsOfPower = " << stereo.wattsOfPower << std::endl;
    std::cout << "numAnalogInputs = " << stereo.numAnalogInputs << std::endl;
    std::cout << "numDigitalInputs = " << stereo.numDigitalInputs << std::endl;
} 

bool CargoShipment::readyForFlight(const Plane& plane)
{
    if (plane.fuelLevel > 3000.0f)
        return true;

    return false;
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    // Wrapper instantiations
    StereoWrapper stWrap( new StereoSystem() );
    MilitaryWrapper mtWrap( new Military() );
    PlaneWrapper plWrap( new Plane() );
    MilitaryTransportWrapper mtTranWrap( new MilitaryTransport() );
    CargoShipmentWrapper cgWrap( new CargoShipment() );
    
    // Instantiations
    StereoSystem::Tape tp1;
    StereoSystem::Tape tp2;
    Military::Soldier soldier;
    
    // StereoSystem
    stWrap.stPtr->playMusic("Remedy Lane", 1);
    stWrap.stPtr->boostBass(7);
    stWrap.stPtr->dubTapes(tp2);
    stWrap.stPtr->destroyTheBass();

    // Tape
    tp1.rewind(false, 50);
    tp1.fastForward(true, 40);
    tp1.getTitle();
    tp1.splice(27);

    // Military
    mtWrap.mtPtr->spendMoney ("Contract 007", 50000000.57f);
    mtWrap.mtPtr->defend (7256);
    mtWrap.mtPtr->invade (234676,7);
    mtWrap.mtPtr->catch22(28);

    // Soldier
    soldier.readyForCombat(160.4f, 4);
    soldier.constructShelter(45, "sunny");
    soldier.skillsAndRank("hand to hand combat", "corporal");
    soldier.weightGainFromPushups(200);

    // Plane
    plWrap.plPtr->transportCargo(175.3);
    plWrap.plPtr->sellAlcohol(8, 4.99f);
    plWrap.plPtr->fly(127, 5000.0f, true);
    plWrap.plPtr->cleanSeats(234);

    // New UDTs
    mtTranWrap.mtTranPtr->getPassengers(*mtWrap.mtPtr);
    mtTranWrap.mtTranPtr->enoughSeats(*mtWrap.mtPtr, *plWrap.plPtr);

    cgWrap.cgPtr->getStereoInfo(*stWrap.stPtr);
    cgWrap.cgPtr->readyForFlight(*plWrap.plPtr);

    // StereoSystem
    std::cout << "st1 numAnalogInputs: " << stWrap.stPtr->numAnalogInputs << " and st1 numDigitalInputs: " << stWrap.stPtr->numDigitalInputs << std::endl; 
    stWrap.stPtr->printDetailedMemberInfo();

    // Tape
    std::cout << "tp1 type: " << tp1.type << " and tp1 getTitle(): " << tp1.getTitle() << std::endl; 
    tp1.printDetailedMemberInfo();

    // Military
    std::cout << "mt numBases: " << mtWrap.mtPtr->numBases << " and mt numSoldiers: " << mtWrap.mtPtr->numSoldiers << std::endl; 
    mtWrap.mtPtr->printDetailedMemberInfo();

    // Soldier
    std::cout << "soldier mainSkill: " << soldier.mainSkill << " and soldier yearsExperience: " << soldier.yearsExperience << std::endl; 
    soldier.printDetailedMemberInfo();

    // Plane
    std::cout << "pl1 typeOfEngine: " << plWrap.plPtr->typeOfEngine << " and pl1 cargoCapacity: " << plWrap.plPtr->cargoCapacity << std::endl; 
    plWrap.plPtr->printDetailedMemberInfo();

    std::cout << "good to go!" << std::endl;
}
