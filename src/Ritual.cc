#include "Ritual.h"
#include "Player.h"

using namespace std;

Ritual::~Ritual() {}

Ritual::Ritual(int cost, Player* player, int charges) : Card{player, cost}, charges{charges} {}

Card::CardType Ritual::getType() const {return RITUAL;}

int Ritual::getCharges() const {return charges;}

void Ritual::loseCharges(int i) {
    charges -= i;
    if (charges < 0) charges =0;
}

void Ritual::play (Board& theBoard, int i, int p, int t) {
  player->moveToRitual(i);
}

// Rituals----------------------------------------------------------------------
DarkRitual::DarkRitual(Player* player) : Ritual{0,player, 5} {
    addAbility("DarkRitual_Ability");
}
string DarkRitual::getName() const { return "Dark Ritual";}

AuraOfPower::AuraOfPower(Player* player) : Ritual{1,player, 4} {
    addAbility("AuraOfPower_Ability");
}
string AuraOfPower::getName() const { return "Aura of Power";}

Standstill::Standstill(Player* player) : Ritual{3,player, 4} {
    addAbility("Standstill_Ability");
}
string Standstill::getName() const { return "Standstill";}
