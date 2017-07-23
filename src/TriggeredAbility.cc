#include "TriggeredAbility.h"

using namespace std;

TriggeredAbility::~TriggeredAbility()
{
    //dtor
}

TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

bool TriggeredAbility::isTriggered() { return true; }



// Triggered Ability Sub classes below

// Minions
// Fire Elemental
FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {}

void FireElemental_Ability::use(Board& theBoard, int p, int t) {
        // go to the most recent minion on enemy field and make it take damage
}
std::string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it";
}

int FireElemental_Ability::isTriggered() { return 69;} // when opponent's minion enters play

// Potion Seller

PotionSeller_Ability::PotionSeller_Ability() : TriggeredAbility(0) {}

void PotionSeller_Ability::use(Board& theBoard, int p, int t) {
        // go through each minion on YOUR board and give it +0/+1
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all your minions gain +0/+1.";
}

int PotionSeller_Ability::isTriggered() {return 69;} // at the end of yourn turn

// Troll Ability

Troll_Ability::Troll_Ability() : TriggeredAbility(0) {}

void Troll_Ability::use(Board& theBoard, int p, int t) {
        // gives all minions on YOUR board +1/+0
}

string Troll_Ability::getDescription() {
    return "When a minion dies, all your minions gain +1/+0"
}

int Troll_Ability::isTriggered() {return 69;} // when a minion dies

// Rituals
// Dark Rital

// Aura of Power

// Standstill
