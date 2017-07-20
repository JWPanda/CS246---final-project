
#include "ActiveAbility.h"

using namespace std;

~ActiveAbility();

//Ctor
ActiveAbility::ActiveAbility(int cost) : cost{cost} {};


bool ActiveAbility::isTriggered() { return false };



// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability(int cost)
 : ActiveAbility{cost} {};

 void NovicePyromancer_Ability::use(Unit& target);
 void NovicePyromancer_Ability::use(Board& theBoard);
string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
};

// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability(int cost)
 : ActiveAbiilty{cost} {};
void ApprenticeSummoner_Ability::use(Unit& target) override;
void ApprenticeSummoner_Ability::se(Board& theBoard) override;
string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
};

// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability(int cost)
 : ActiveAbiilty{cost} {};
void MasterSummoner_Ability::use(Unit& target);
void MasterSummoner_Ability::use(Board& theBoard);
string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals"
};

