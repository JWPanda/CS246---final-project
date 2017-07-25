#include "TriggeredAbility.h"
#include <iostream>

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

TriggeredAbility::~TriggeredAbility() {}


//Minion Triggered Abilities----------------------------------------------------


// Fire Elemental
FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {}

void FireElemental_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
        if(friendly != enemy && target->onBoard()) {
            target->getHit(1);
        }
}
string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it";
}

Ability::AbilityType FireElemental_Ability::checkAbility() {
  return Ability::ENTER;
}

// Potion Seller
PotionSeller_Ability::PotionSeller_Ability() : TriggeredAbility(0) {}

void PotionSeller_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
    // go through each minion on YOUR board and give it +0/+1
    for(auto c : friendly->getField()) {
        dynamic_cast<Unit*>(c)->gainStats(0,1);
    }
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all your minions gain +0/+1.";
}

Ability::AbilityType PotionSeller_Ability::checkAbility() {
  return Ability::END;
}

// Troll Ability
Troll_Ability::Troll_Ability() : TriggeredAbility(0) {}

void Troll_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
            // go through each minion on YOUR board and give it +1/+0
    for(auto c : friendly->getField()) {
        dynamic_cast<Unit*>(c)->gainStats(1,0);
    }
}

string Troll_Ability::getDescription() {
    return "When a minion dies, all your minions gain +1/+0";
}

Ability::AbilityType Troll_Ability::checkAbility() {
  return Ability::DEATH;
}


//Rituals-----------------------------------------------------------------------


//Dark Ritual
DarkRitual_Ability::DarkRitual_Ability() : TriggeredAbility(1) {}

void DarkRitual_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
    myPlayer->gainMana()
}
std::string DarkRitual_Ability::getDescription() {
    return "At the start of your turn, gain 1 magic";
}

Ability::AbilityType DarkRitual_Ability::checkAbility() {
  return Ability::BEGIN;
}

//Aura of Power
AuraOfPower_Ability::AuraOfPower_Ability() : TriggeredAbility(1) {}

void AuraOfPower_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
    if (enemy == friendly && target->onBoard()){
        target->gainStats(1,1);
    }
}
std::string AuraOfPower_Ability::getDescription() {
    return "Whenever a minion enters play under your control, it gains +1/+1";
}

Ability::AbilityType AuraOfPower_Ability::checkAbility() {
  return Ability::ENTER;
}


//Standstill
Standstill_Ability::Standstill_Ability() : TriggeredAbility(2) {}

void Standstill_Ability::use(Board& theBoard, Unit* target, Player* enemy, Player* friendly)  {
    if (target->onBoard()) target->die();
}
std::string Standstill_Ability::getDescription() {
    return "Whenever a minion enters play, destory it";
}

Ability::AbilityType Standstill_Ability::checkAbility() {
  return Ability::ENTER;
}

// Elemental Party
ElementalParty_Ability::ElementalParty_Ability() : TriggeredAbility{2} {}

void ElementalParty_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer) {
    for (int i = 1, i < 3, ++i) {
        for(auto c: theBoard.getPlayer(i)->getField()) {
        istringstream ss{c->getName()};
        string s;
        while (ss >> s){
            if (s == "Elemental") {
                dynamic_cast<Unit*>(c)->gainStats(3,3);
                break;
            }
        }
    }
  }
}
string ElementalParty_Ability::getDescription() {
    return "Whenever a minion with the name \"Elemental\" enters play, all Elementals gain +3/+3";
}

Ability::AbilityType ElementalParty_Ability::checkAbility() {
    return Ability::ENTER;
}
