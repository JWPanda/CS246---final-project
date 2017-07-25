#include "Spell.h"

using namespace std;

Spell::Spell(int cost, Player* player) : Card{player, cost} {}

Spell::~Spell()
{
    //dtor
}

Card::CardType Spell::getType() const {return Card::SPELL;}

void Spell::play(Board& theBoard, int i, int p, int t) {
    use(theBoard, p,t);
}

// Spell Cards
//Banish
Banish::Banish(Player* player) : Spell{2,player} {
    addAbility("Banish_Ability");
}
string Banish::getName() const { return "Banish";}

// Unsummon
Unsummon::Unsummon(Player* player) : Spell{1,player} {
    addAbility("Unsummon_Ability");
}
string Unsummon::getName() const { return "Unsummon";}

// Recharge
Recharge::Recharge(Player* player) : Spell{1,player} {
    addAbility("Recharge_Ability");
}
string Recharge::getName() const { return "Recharge";}

// Disenchant
Disenchant::Disenchant(Player* player) : Spell{1,player} {
    addAbility("Disenchant_Ability");
}
string Disenchant::getName() const { return "Disenchant";}

// Raise Dead
RaiseDead::RaiseDead(Player* player) : Spell{1,player} {
    addAbility("RaiseDead_Ability");
}
string RaiseDead::getName() const { return "Raise Dead";}

// Blizzard
Blizzard::Blizzard(Player* player) : Spell{3,player} {
    addAbility("Blizzard_Ability");
}
string Blizzard::getName() const { return "Blizzard";}
