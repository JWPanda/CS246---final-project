#include "TriggeredAbility.h"

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

TriggeredAbility::~TriggeredAbility() {}

//Trigger Implementation--------------------------------------------------------
int TriggeredAbility::isTriggered() { return 4; }

//Triggered Ability Sub classes below-------------------------------------------


// Fire Elemental
FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {}

void FireElemental_Ability::use(Board& theBoard, int p, int t) {
    if (p == 69) { // trigger on play minion
        // go to the most recent minion on enemy field and make it take damage
    }
}
std::string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enters play, deal 1 damage to it";
}


// Potion Seller
PotionSeller_Ability::PotionSeller_Ability() : TriggeredAbility(0) {}

void PotionSeller_Ability::use(Board& theBoard, int p, int t) {
    if (p == 69) { // trigger on end of YOUR turn
        // go through each minion on YOUR board and give it +0/+1
    }
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all your minions gain +0/+1.";
}


// Troll Ability
Troll_Ability::Troll_Ability() : TriggeredAbility(0) {}

void Troll_Ability::use(Board& theBoard, int p, int t) {
    if (p == 69) { // trigger on end death of minion
        // gives all minions on YOUR board +1/+0
    }
}

string Troll_Ability::getDescription() {
    return "When a minion dies, all your minions gain +1/+0"
}
