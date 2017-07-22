#include "ActiveAbility.h"

using namespace std;

~ActiveAbility();

//Ctor
ActiveAbility::ActiveAbility(int cost) : Ability{cost} {};


bool ActiveAbility::isTriggered() { return false };



// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability()
 : ActiveAbility{1} {};

 void NovicePyromancer_Ability::use(Board& theBoard, int p, int t) {
     if (t < 0) throw; // did not target a minion

     // go to player p and find minion t
     // make it take 1 damage
     // call minion getHit(1);
 }

string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
};

// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability()
 : ActiveAbiilty{1} {};

void ApprenticeSummoner_Ability::use(Board& theBoard, int t, int p) {
    // check if active player field is full, if so throw an exception

    // if board is not full, create an air elemental on active player board
    // create air elemental by AirElemental(player*)
}

string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
};

// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability()
 : ActiveAbiilty{2} {};

void MasterSummoner_Ability::use(Board& theBoard, int t, int p) {
    // check if actvie player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned on active player board
    // AirElemental(player*)
}
string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals";
};
