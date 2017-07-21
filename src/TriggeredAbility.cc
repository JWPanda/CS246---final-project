#include "TriggeredAbility.h"

using namespace std;

TriggeredAbility::TriggeredAbility()
{
    //ctor
}

TriggeredAbility::~TriggeredAbility()
{
    //dtor
}

TriggeredAbility::TriggeredAbility(int cost) : Ability{cost} {}

bool TriggeredAbility::isTriggered() { return true; }


// Triggered Ability Sub classes below

// Fire Elemental

FireElemental_Ability::FireElemental_Ability() : TriggeredAbility(0) {};

void FireElemental_Ability::use(Board& theBoard, int i) {
    if (i == 69) { // trigger on play minion
        // go to the most recent minion on enemy field and make it take damage
    }
}
std::string FireElemental_Ability::getDescription() {
    return "Whenever an opponent's minion enteres play, deal 1 damage to it"
};

// Potion Seller
void PotionSeller_Ability::use(Board& theBoard, int i) {
    if (i == 69) { // trigger on end of YOUR turn
        // go through each minion on YOUR board and give it +0/+1
    }
}

string PotionSeller_Ability::getDescription() {
    return "At the end of your turn, all minions gain +0/+1."
}
