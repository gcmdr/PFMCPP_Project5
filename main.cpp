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
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include "Wrappers.h"
#include "Plane.h"
#include "CargoShipment.h"
#include "MilitaryTransport.h"
#include "StereoSystem.h"
#include "Military.h"

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
