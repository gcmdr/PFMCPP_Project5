#include "StereoSystem.h"

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

StereoSystem::Tape::~Tape()
{
    std::cout << "Tape dtor" << std::endl;
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
