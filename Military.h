#include <iostream>

struct Military
{
    Military();
    ~Military();
    
    std::string branchOfMilitary;
    int numBases;
    int numSoldiers = 5000;
    float budget = 10000000.0f;
    int numReserveSoldiers = 1000;

    struct Soldier
    {
        Soldier();
        ~Soldier();

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