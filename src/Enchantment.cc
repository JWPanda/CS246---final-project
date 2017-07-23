<<<<<<< HEAD
#include "Enchantment.h"

using namespace std;

Enchantment::Enchantment(int cost,int Attack, int Defense, Player* player)
: Unit{cost, Attack, Defense, player} {};

Enchantment::~Enchantment();

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

Enchantment * Enchantment::enchant(Unit& target) {
    attack = target.getAttack();
    defense = target.getDefense();
    base = &target;
    return this;
}

void Enchantment::die() {
    if (getEnchantmentAttack() > 0) base->reduceAttack(getEnchantmentAttack());
    if (getEnchantmentDefense() > 0) base->getHit(getEnchantmentAttack());
    // IDK
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

// Magic Fatigue
magicFatigue::magicFatigue(Player* player) : Enchantment{0,-1,-1,player} {}
string magicFatigue::getEnchantmentDescription() {
    return "Enchanted minion's activated ability costs 2 more"
}
int getAbilityCost() {
    return base->getAbilityCost() + 2;
}

// Silence
silence::silence(Player* player) : Enchantment{1,-1,-1,player};
string silence::getEnchantmentDescription() {
    return "Enchanted minion cannot use abilities"
}
bool hasAbility() {
    return false; // or throw?
}
=======
#include "Enchantment.h"

using namespace std;

Enchantment::Enchantment(int cost,int Attack, int Defense, Player* player)
: Unit{cost, Attack, Defense, player} {};

Enchantment::~Enchantment();

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

CardType Enchantment::getType() {return ENCHANTMENT;}

Enchantment * Enchantment::enchant(Unit& target) {
    attack = target.getAttack();
    defense = target.getDefense();
    base = &target;
    return this;
}

void Enchantment::die() {
    if (getEnchantmentAttack() > 0) base->reduceAttack(getEnchantmentAttack());
    if (getEnchantmentDefense() > 0) base->getHit(getEnchantmentAttack());
    // IDK
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

// Magic Fatigue
magicFatigue::magicFatigue(Player* player) : Enchantment{0,-1,-1,player} {}
string magicFatigue::getEnchantmentDescription() {
    return "Enchanted minion's activated ability costs 2 more"
}
int getAbilityCost() {
    return base->getAbilityCost() + 2;
}

// Silence
silence::silence(Player* player) : Enchantment{1,-1,-1,player};
string silence::getEnchantmentDescription() {
    return "Enchanted minion cannot use abilities"
}
bool hasAbility() {
    return false; // or throw?
}
>>>>>>> Modify card templates to check different card types and add enumeration
