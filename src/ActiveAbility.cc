#include "ActiveAbility.h"

using namespace std;

~ActiveAbility();

//Ctor
ActiveAbility::ActiveAbility(int cost) : Ability{cost} {};


bool ActiveAbility::isTriggered() { return false };



// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability()
 : ActiveAbility{1} {};

 void NovicePyromancer_Ability::use(Board& theBoard, int i) {
     // find minion i on enemy borad
     // make it take 1 damage
 }

string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
};

// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability()
 : ActiveAbiilty{1} {};

void ApprenticeSummoner_Ability::use(Board& theBoard, int i) {
    // check if player field is full, if so throw an exception
    // if board is not full, create an air elemental on board
}

string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
};

// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability()
 : ActiveAbiilty{2} {};

void MasterSummoner_Ability::use(Board& theBoard, int i) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals"
};