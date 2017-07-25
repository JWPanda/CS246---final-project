#include "Enchantment.h"
#include "Player.h"

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
Enchantment::Enchantment(int cost,int Attack, int Defense, Player* player)
: Unit{cost, Attack, Defense, player}, base{nullptr},  enchantmentCost(cost){}

Enchantment::~Enchantment() {}


//Game Mechanics----------------------------------------------------------------
void Enchantment::play (Board& theBoard, int i, int p, int t) {
  player->moveToBoard(this);
}

// Enchantment * Enchantment::enchant(Unit* target) {  //TODO smart pointer here
//     Attack = target->getAttack();
//     Defense = target->getDefense();
//     cost = target->getCost();
//     base = target;
//     return this;
// }

void Enchantment::die() {
    if (getEnchantmentAttack() > 0) base->reduceAttack(getEnchantmentAttack());
    if (getEnchantmentDefense() > 0) base->getHit(getEnchantmentAttack());
    // IDK
}


//Accessors---------------------------------------------------------------------

Card::CardType Enchantment::getType() const { return Card::ENCHANTMENT; }

string Enchantment::getName() const {
  if (base) return base->getName();
  else return getEnchantmentName();
}

string Enchantment::getDescription() const {
    if (base) return base->getDescription();
    else return getEnchantmentDescription();
}

Unit* Enchantment::getBase() {
    return base;
}

int Enchantment::getEnchantmentCost() const {
    if (base) return base->getCost();
    else return getCost();
}
int Enchantment::getEnchantmentAttack() const {
    return BaseAttack;
};

int Enchantment::getEnchantmentDefense() const {
    return BaseDefense;
};


// Enchantment Subclasses-------------------------------------------------------

// Giant Strength
GiantStrength::GiantStrength(Player* player) :
    Enchantment{1,2,2,player} {}
string GiantStrength::getEnchantmentName() const {return "Giant Strength";}
/*Enchantment* GiantStrength::enchant(Unit& target) {
    Attack = target.getAttack() + 2;
    Defense = target.getDefense() + 2;
    base = &target;
    return this;
}*/

// Magic Fatigue
MagicFatigue::MagicFatigue(Player* player) : Enchantment{0,-1,-1,player} {}
string MagicFatigue::getEnchantmentName() const {return "Magic Fatigue";}
string MagicFatigue::getEnchantmentDescription() const
{
    return "Enchanted minion's activated ability costs 2 more";
}
int MagicFatigue::getAbilityCost() const {
    return base->getAbilityCost() + 2;
}

// Silence
Silence::Silence(Player* player) : Enchantment{1,-1,-1,player} {}
string Silence::getEnchantmentName() const {return "Silence";}
string Silence::getEnchantmentDescription() const
{
    return "Enchanted minion cannot use abilities";
}
bool Silence::hasAbility() const {
    return false;
}
