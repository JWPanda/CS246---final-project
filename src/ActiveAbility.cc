#include "ActiveAbility.h"
#include "Player.h"
#include "Board.h"
#include "Minion.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
ActiveAbility::ActiveAbility(int cost) : Ability{cost} {}

ActiveAbility::~ActiveAbility() {}

// Trigger Implementation-------------------------------------------------------
Ability::AbilityType ActiveAbility::checkAbility () { return Ability::ACTIVE;}

// Minion Abilities-------------------------------------------------------------



// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability() : ActiveAbility{1} {}


void NovicePyromancer_Ability::use(Board& theBoard, int p , int t) {
    theBoard.getMinion(t,p)->getHit(1);
}

string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
}



// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability() : ActiveAbility{1} {}

void ApprenticeSummoner_Ability::use(Board& theBoard, int p , int t) {
    Player * myPlayer = theBoard.getActivePlayer();
    int fieldSize = myPlayer->getField().size();
    if (fieldSize == 5) throw "Error: there are already 5 cards on your field"s;
    myPlayer->moveToBoard(make_shared<AirElemental>(myPlayer));
}

string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
}



// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability(): ActiveAbility{2} {}

void MasterSummoner_Ability::use(Board& theBoard, int p , int t){
  Player * myPlayer = theBoard.getActivePlayer();
  int fieldSize = theBoard.getActivePlayer()->getField().size();
  if (fieldSize == 5) throw "Error: there are already 5 cards on your field"s;

    // loop until board is full or 3 air elementals are summoned
    for (int i = 0; i < 3; ++i) {
        if (myPlayer->getField().size() >= 5) break;
    myPlayer->moveToBoard(make_shared<AirElemental>(myPlayer));
    }
}

string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals";
}



// Spell Abilities--------------------------------------------------------------
// Banish
Banish_Ability::Banish_Ability() : ActiveAbility{0} {}

void Banish_Ability::use(Board& theBoard, int p , int t){
    // if target is a ritual
    if (t == 6) {
        theBoard.getPlayer(p)->destroyRitual();
    }
    else {// target is a minion
        // if target card is a minion,
        theBoard.getMinion(t,p)->die(); // change if target is a pointer
    }
}
string Banish_Ability::getDescription() {
    return "Destroy target minion or ritual";
}


// Unsummon
Unsummon_Ability::Unsummon_Ability(): ActiveAbility{0} {}

void Unsummon_Ability::use(Board& theBoard, int p , int t){
    // idea 2:
    theBoard.getMinion(t,p)->unsummon();
}

string Unsummon_Ability::getDescription() {
    return "Put Target minion on the bottom of its owner's deck";
}


// Recharge
Recharge_Ability::Recharge_Ability() : ActiveAbility{0} {}

void Recharge_Ability::use(Board& theBoard, int p , int t){
  Player * myPlayer = theBoard.getActivePlayer();
  dynamic_pointer_cast<Ritual>(myPlayer->getRitual())->increaseCharges(3);
}
string Recharge_Ability::getDescription() {
    return "Your ritual gains 3 charges";
}


// Disenchant
Disenchant_Ability::Disenchant_Ability() : ActiveAbility{0} {}

void Disenchant_Ability::use(Board& theBoard, int p , int t){
    theBoard.getMinion(t, p)->disenchant();
}

string Disenchant_Ability::getDescription() {
    return "Destroy the top enchantment on target minion";
}


// Raise Dead
RaiseDead_Ability::RaiseDead_Ability(): ActiveAbility{0} {};

void RaiseDead_Ability::use(Board& theBoard, int p , int t) {
    theBoard.getActivePlayer()->revive();
}
string RaiseDead_Ability::getDescription() {
    return "Resurrect the top minion on your graveyard";
}

// Blizzard
Blizzard_Ability::Blizzard_Ability() : ActiveAbility{0} {}

void Blizzard_Ability::use(Board& theBoard, int p , int t){
    for (auto c : theBoard.getActivePlayer()->getField()) {
       dynamic_pointer_cast<Unit>(c)->getHit(2);
     }
    for (auto c : theBoard.getNonActivePlayer()->getField()) {
        dynamic_pointer_cast<Unit>(c)->getHit(2);
     }
}

string Blizzard_Ability::getDescription() {
    return "Deal 2 damage to all minions";
}
