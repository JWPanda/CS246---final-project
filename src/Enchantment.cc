#include "Enchantment.h"

using namespace std;

Enchantment::Enchantment(int cost,int Attack, int Defense, Player* player)
: Unit{cost, Attack, Defense, player} {};

Enchantment::~Enchantment();

void Enchantment::play (Board& theBoard, int i, int p, int t)
    if (p == 1) {
        enchant(theBoard.getP1().getMinion(t));
        theBoard.getP1().replaceOnBoard(i,t); // replaces card t on field with card i on board
    }
}

string Enchantment::getName() {
    if (base) return base->getDescription();
    else return getEnchantmentName();
}

string Enchantment::getDescription() {
    if (base) return base->getDescription();
    else return getEnchantmentDescription();
}

int Enchantment::getEnchantmentAttack() {
    return BaseAttack;
};
int getEnchantmentDefense() {
    return BaseDefense;
};

int Enchantment::getType() { return 4};

void Enchantment::enchant(Unit& target) {
    attack = target.getAttack();
    defense = target.getDefense();
    ability = target.ability;
    base = &target;
}

void Enchantment::disenchant() {
    // replaces the unit on the board with the base
    if (getEnchantmentAttack() > 0) base->reduceAttack(getEnchantmentAttack());
    if (getEnchantmentDefense() > 0) base->getHit(getEnchantmentAttack());
    // remove this enchantment from game

}

void Enchantment::die() {
    // replace the unit on the board with the base
    base->die();
}

// Enchantment Subclasses

// Giant Strength
giantStrength::giantStrength(Player* player) :
    Enchantment{1,2,2,player} {}

Enchantment* giantStrength::enchant(Unit& target) {
    attack = target.getAttack() + 2;
    defense = target.getDefense() +2;
    base = &target;
    return this;
}

string giantStrength::getEnchantmentName() { return "giantStrenth"}

// Magic Fatigue
magicFatigue::magicFatigue(Player* player) : Enchantment{0,-1,-1,player} {}
string magicFatigue::getEnchantmentDescription() {
    return "Enchanted minion's activated ability costs 2 more"
}
int getAbilityCost() {
    return base->getAbilityCost() + 2;
}

string magicFatigue::getEnchantmentName() { return "Magic Fatigue"}

// Silence
silence::silence(Player* player) : Enchantment{1,-1,-1,player};
string silence::getEnchantmentDescription() {
    return "Enchanted minion cannot use abilities"
}
bool hasAbility() {
    return false; // or throw?
}

string silence::getEnchantmentName() { return "Silence"}
