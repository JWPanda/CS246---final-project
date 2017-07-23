#include "ActiveAbility.h"

using namespace std;

~ActiveAbility();

//Ctor
ActiveAbility::ActiveAbility(int cost) : Ability{cost} {};


int ActiveAbility::isTriggered() { return -1};



// Minion Abilities
// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability()
 : ActiveAbility{1} {};

 void NovicePyromancer_Ability::use(Board& theBoard, int t, int p) {
     // find minion i on enemy borad
     // make it take 1 damage
 }

string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
};

// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability()
 : ActiveAbiilty{1} {};

void ApprenticeSummoner_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception
    // if board is not full, create an air elemental on board
}

string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
};

// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability()
 : ActiveAbiilty{2} {};

void MasterSummoner_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals"
};


// Spell Abilities
// Banish
Banish_Ability::Banish_Ability()
 : ActiveAbiilty{0} {};

void Banish_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string Banish_Ability::getDescription() {
    return "Destroy target minion or ritual"
};

// Unsummon
Unsummon_Ability::Unsummon_Ability()
 : ActiveAbiilty{0} {};

void Unsummon_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string Unsummon_Ability::getDescription() {
    return "Put Target minion on the bottom of its owner's deck"
};

// Recharge
Recharge_Ability::Recharge_Ability()
 : ActiveAbiilty{0} {};

void Recharge_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string Recharge_Ability::getDescription() {
    return "Your ritual gains 3 charges"
};

// Disenchant
Disenchant_Ability::Disenchant_Ability()
 : ActiveAbiilty{0} {};

void Disenchant_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string Disenchant_Ability::getDescription() {
    return "Destroy the top enchantment on target minion"
};

// Raise Dead
RaiseDead_Ability::RaiseDead_Ability()
 : ActiveAbiilty{0} {};

void RaiseDead_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string RaiseDead_Ability::getDescription() {
    return "Resurrect the top minion on your graveyard"
};

// Blizzard
Blizzard_Ability::Blizzard_Ability()
 : ActiveAbiilty{0} {};

void Blizzard_Ability::use(Board& theBoard, int t, int p) {
    // check if player field is full, if so throw an exception

    // loop until board is full or 3 air elementals are summoned
}
string Blizzard_Ability::getDescription() {
    return "Destroy target minion or ritual"
};
