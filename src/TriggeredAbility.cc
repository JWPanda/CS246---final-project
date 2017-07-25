#include "TriggeredAbility.h"
#include <iostream>

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

TriggeredAbility::~TriggeredAbility() {}


//Minion Triggered Abilities----------------------------------------------------


// Fire Elemental
FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {}

void FireElemental_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Fire Elemental" << endl;
}
string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it";
}

Ability::AbilityType FireElemental_Ability::checkAbility() {
  return Ability::ENTER;
}

// Potion Seller
PotionSeller_Ability::PotionSeller_Ability() : TriggeredAbility(0) {}

void PotionSeller_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Potion Seller" << endl;
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all your minions gain +0/+1.";
}

Ability::AbilityType PotionSeller_Ability::checkAbility() {
  return Ability::END;
}

// Troll Ability
Troll_Ability::Troll_Ability() : TriggeredAbility(0) {}

void Troll_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Troll" << endl;
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

void DarkRitual_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Dark Ritual" << endl;
}
std::string DarkRitual_Ability::getDescription() {
    return "At the start of your turn, gain 1 magic";
}

Ability::AbilityType DarkRitual_Ability::checkAbility() {
  return Ability::BEGIN;
}

//Aura of Power
AuraOfPower_Ability::AuraOfPower_Ability() : TriggeredAbility(1) {}

void AuraOfPower_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Aura of Power" << endl;
}
std::string AuraOfPower_Ability::getDescription() {
    return "Whenever a minion enters play under your control, it gains +1/+1";
}

Ability::AbilityType AuraOfPower_Ability::checkAbility() {
  return Ability::ENTER;
}


//Standstill
Standstill_Ability::Standstill_Ability() : TriggeredAbility(2) {}

void Standstill_Ability::use(Board& theBoard, shared_ptr<Unit> target, Player* enemy, Player* friendly)  {
    cout << "Standstill" << endl;
}
std::string Standstill_Ability::getDescription() {
    return "Whenever a minion enters play, destory it";
}

Ability::AbilityType Standstill_Ability::checkAbility() {
  return Ability::ENTER;
}
