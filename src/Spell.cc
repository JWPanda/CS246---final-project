#include "Spell.h"

Spell::Spell(int cost, Player* player) : Card(cost,player) {}

Spell::~Spell()
{
    //dtor
}

play(Board& theBoard, int i, int p, int t) {
    use(theBoard, p,t);
    player->discard(i);
}

// Spell Cards
//Banish
Banish::Banish(Player* player) : Spell{2,player} {
    addAbility("Banish_Ability");
}
string Banish::getName() { return "Banish"}

// Unsummon
Unsummon::Unsumon(Player* player) : Spell{1,player} {
    addAbility("Unsummon_Ability");
}
string Unsummon::getName() { return "Unsummon"}

// Recharge
Recharge::Recharge(Player* player) : Spell{1,player} {
    addAbility("Recharge_Ability");
}
string Recharge::getName() { return "Recharge"}

// Disenchant
Disenchant::Disenchant(Player* player) : Spell{1,player} {
    addAbility("Disenchant_Ability");
}
string Disenchant::getName() { return "Disenchant"} {
}

// Raise Dead
RaiseDead::RaiseDead(Player* player) : Spell{1,player} {
    addAbility("RaiseDead_Ability");
}
string RaiseDead::getName() { return "Raise Dead"}

// Blizzard
Blizzard::Blizzard(Player* player) : Spell{3,player} {
    addAbility("Blizzard_Ability");
}
string Blizzard::getName() { return "Blizzard"}

