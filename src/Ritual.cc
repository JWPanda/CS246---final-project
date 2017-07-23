#include "Ritual.h"

using namespace std;

Ritual::~Ritual()
{
    //dtor
}

Ritual::Ritual(int cost, Player* player, int charges) : Card{cost, player}, charges{charges} {}

CardType Ritual::getType() {return RITUAL;}

void Ritual::loseCharges(int i) {
    charges -= i;
    if (charges < 0) charges =0;
}

// Rituals

DarkRitual::DarkRitual(Player* player) : Ritual{0,player, 5} {
    addAbility("DarkRitual_Ability");
}
string DarkRitual::getName() { return "Dark Ritual";}

AuraOfPower::AuraOfPower(Player* player) : Ritual{1,player, 4} {
    addAbility("AuraOfPower_Ability");
}
string AuraOfPower::getName() { return "Aura of Power";}

Standstill::Standstill(Player* player) : Ritual{3,player, 4} {
    addAbility("Standstill_Ability");
}
string Standstill::getName() { return "Standstill";}
