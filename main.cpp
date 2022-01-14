/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/*
 copied UDT 1:
 */
struct StereoSystem
{
    StereoSystem();
    ~StereoSystem()
    {
        std::cout << "StereoSystem dtor" << std::endl;
    }
    int numSpeakers = 2;
    float wattsOfPower = 60.0f;
    int numAnalogInputs = 2;
    int numDigitalInputs = 2;
    int numEQBands;
    bool subOn;
    int maxBassLevel;
    int bassLevel;

    struct Tape
    {
        Tape();
        ~Tape()
        {
            std::cout << "Tape dtor" << std::endl;
        }
        std::string tapeName = "mix";
        std::string type = "chrome bias";
        float quality;
        int minPerSide;
        int positionInMinutes;

        void rewind(bool beginning, int lengthOfTime);
        void fastForward(bool end, int lengthOfTime);
        std::string getTitle();
        void splice(int lengthOfSplice);
        void printDetailedMemberInfo();
    };

    void playMusic(std::string album, int track);
    void boostBass(int bassBoostAmount = 5);
    Tape dubTapes(Tape tape1);
    void destroyTheBass();
    void printDetailedMemberInfo();

    Tape originalTape;
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

StereoSystem::Tape StereoSystem::dubTapes(Tape tape1)
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

    int getPassengers(Military newArmy);
    bool enoughSeats(Military newArmy, Plane armyPlane);
};

MilitaryTransport::MilitaryTransport()
{
    std::cout << "MilitaryTransport ctor" << std::endl;
}

int MilitaryTransport::getPassengers(Military army)
{
    return army.numSoldiers;
}

bool MilitaryTransport::enoughSeats(Military army, Plane plane)
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

    void getStereoInfo(StereoSystem st1);
    bool readyForFlight(Plane musicPlane);
};

CargoShipment::CargoShipment()
{
    std::cout << "CargoShipment ctor" << std::endl;
}

void CargoShipment::getStereoInfo(StereoSystem stereo)
{
    std::cout << "numSpeakers: " << stereo.numSpeakers << std::endl;
    std::cout << "wattsOfPower = " << stereo.wattsOfPower << std::endl;
    std::cout << "numAnalogInputs = " << stereo.numAnalogInputs << std::endl;
    std::cout << "numDigitalInputs = " << stereo.numDigitalInputs << std::endl;
} 

bool CargoShipment::readyForFlight(Plane plane)
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
    // Instantiations
    StereoSystem st1;
    StereoSystem::Tape tp1;
    StereoSystem::Tape tp2;
    Military mt;
    Military::Soldier soldier;
    Plane pl1;
    Plane pl2;

    // StereoSystem
    st1.playMusic("Remedy Lane", 1);
    st1.boostBass(7);
    st1.dubTapes(tp2);
    st1.destroyTheBass();

    // Tape
    tp1.rewind(false, 50);
    tp1.fastForward(true, 40);
    tp1.getTitle();
    tp1.splice(27);

    // Military
    mt.spendMoney ("Contract 007", 50000000.57f);
    mt.defend (7256);
    mt.invade (234676,7);
    mt.catch22(28);

    // Soldier
    soldier.readyForCombat(160.4f, 4);
    soldier.constructShelter(45, "sunny");
    soldier.skillsAndRank("hand to hand combat", "corporal");
    soldier.weightGainFromPushups(200);

    // Plane
    pl1.transportCargo(175.3);
    pl1.sellAlcohol(8, 4.99f);
    pl1.fly(127, 5000.0f, true);
    pl1.cleanSeats(234);

    // New UDTs
    MilitaryTransport mtr;
    mtr.getPassengers(mt);
    mtr.enoughSeats(mt, pl1);

    CargoShipment cgo;
    cgo.getStereoInfo(st1);
    cgo.readyForFlight(pl2);

    // StereoSystem
    std::cout << "st1 numAnalogInputs: " << st1.numAnalogInputs << " and st1 numDigitalInputs: " << st1.numDigitalInputs << std::endl; 
    st1.printDetailedMemberInfo();

    // Tape
    std::cout << "tp1 type: " << tp1.type << " and tp1 getTitle(): " << tp1.getTitle() << std::endl; 
    tp1.printDetailedMemberInfo();

    // Military
    std::cout << "mt numBases: " << mt.numBases << " and mt numSoldiers: " << mt.numSoldiers << std::endl; 
    mt.printDetailedMemberInfo();

    // Soldier
    std::cout << "soldier mainSkill: " << soldier.mainSkill << " and soldier yearsExperience: " << soldier.yearsExperience << std::endl; 
    soldier.printDetailedMemberInfo();

    // Plane
    std::cout << "pl1 typeOfEngine: " << pl1.typeOfEngine << " and pl1 cargoCapacity: " << pl1.cargoCapacity << std::endl; 
    pl1.printDetailedMemberInfo();

    std::cout << "good to go!" << std::endl;
}
