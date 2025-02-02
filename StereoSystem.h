#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct StereoSystem
{
    StereoSystem();
    ~StereoSystem();
    
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
        ~Tape();
        
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
    Tape dubTapes(Tape& tape1);
    void destroyTheBass();
    void printDetailedMemberInfo();

    Tape originalTape;
    JUCE_LEAK_DETECTOR(StereoSystem)
};
