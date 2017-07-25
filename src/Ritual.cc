#include "Ritual.h"
#include "Player.h"

using namespace std;


//Ctor and Dtor:
Ritual::Ritual(int cost, Player* player, int charges) : Card{player, cost}, charges{charges} {}

Ritual::~Ritual() {}


//Game Mechanics:
void Ritual::loseCharges(int i) {
    charges -= i;
    if (charges < 0) charges =0;
}

void Ritual::play (Board& theBoard, int i, int p, int t) {
  player->moveToRitual(i);
}


//Accessors
Card::CardType Ritual::getType() const {return RITUAL;}

int Ritual::getCharges() const {return charges;}


// Rituals----------------------------------------------------------------------

//Dark Ritual:
DarkRitual::DarkRitual(Player* player) : Ritual{0,player, 5} {
    addAbility("DarkRitual_Ability");
}
string DarkRitual::getName() const { return "Dark Ritual";}


//Aura of Power:
AuraOfPower::AuraOfPower(Player* player) : Ritual{1,player, 4} {
    addAbility("AuraOfPower_Ability");
}
string AuraOfPower::getName() const { return "Aura of Power";}

//Standstill:
Standstill::Standstill(Player* player) : Ritual{3,player, 4} {
    addAbility("Standstill_Ability");
}
string Standstill::getName() const { return "Standstill";}
