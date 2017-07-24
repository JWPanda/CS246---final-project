#include "TriggeredAbility.h"

using namespace std;

TriggeredAbility::~TriggeredAbility()
{
    //dtor
}

TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

// Triggered Ability Sub classes below

// Minions
// Fire Elemental
FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {}

void FireElemental_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer){
        // if(targetPlayer != myPlayer) {
        // target->getHit(1);
        // }

        // what happens if target dies before reaching this trigger check...
        //    1. minion takes damage while in the graveyard
        //    2. minion can die again in the graveyard -> BAAAAADDDDAADADAA
        // Possible Solutions:
        //   i. have a dead/alive (onfield/not on field) method to prevent this
        //   ii. cry
}
std::string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it";
}

int FireElemental_Ability::isTriggered() { return 69;} // when opponent's minion enters play

// Potion Seller

PotionSeller_Ability::PotionSeller_Ability() : TriggeredAbility(0) {}

void PotionSeller_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer){
        // go through each minion on YOUR board and give it +0/+1
        // for(auto c : myPlayer->getField()) {
        //  c->gainDefense(1);
        // }
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all your minions gain +0/+1.";
}

int PotionSeller_Ability::isTriggered() {return 69;} // at the end of yourn turn

// Troll Ability

Troll_Ability::Troll_Ability() : TriggeredAbility(0) {}

void Troll_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer) {
        // go through each minion on YOUR board and give it +1/+0
        // for(auto c : myPlayer->getField()) {
        //  c->gainAttack(1);
        // }
}

string Troll_Ability::getDescription() {
    return "When a minion dies, all your minions gain +1/+0";
}

int Troll_Ability::isTriggered() {return 69;} // when a minion dies

// Rituals
// Dark Rital
DarkRitual_Ability::DarkRitual_Ability() : TriggeredAbility(1) {}

void DarkRitual_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer) {
        // myPlayer->gainMana();
        // need implement gain mana for player
}

string DarkRitual_Ability::getDescription() {
    return "At the start of your turn, gain 1 magic";
}

int DarkRitual_Ability::isTriggered() {return 69;} //

// Aura of Power
AuraOfPower_Ability::AuraOfPower_Ability() : TriggeredAbility(1) {}

void AuraOfPower_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer) {
        // if (targetPlayer == myPlayer) {
        //    target->gainDefense(1);
        //    target->gainAttack(1);
        //  }
}

string AuraOfPower_Ability::getDescription() {
    return "Whenever a minion enters play under your control, it gains +1/+1";
}

int AuraOfPower_Ability::isTriggered() {return 69;} //

// Standstill
Standstill_Ability::DarkRitual_Ability() : TriggeredAbility(2) {}

void Standstill_Ability::use(Board& theBoard, Card* target, Player* targetPlayer, Player* myPlayer) {
        // target->die();
}

string Standstill_Ability::getDescription() {
    return "Whenever a minon enters play, destroy it";
}

int Standstill_Ability::isTriggered() {return 69;} //
    x
