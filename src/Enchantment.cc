#include "Enchantment.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
Enchantment::Enchantment(int cost,int Attack, int Defense, Player* player)
: Unit{cost, Attack, Defense, player}, base{nullptr},  enchantmentCost(cost){}

Enchantment::~Enchantment() {}


//Game Mechanics----------------------------------------------------------------
void Enchantment::play (Board& theBoard, int i, int p, int t) {
    enchant(theBoard.getMinion(t,p));
    shared_ptr<Unit> u = shared_from_this();
    player->placeEnchantment(dynamic_pointer_cast<Card>(u));
}

void Enchantment::enchant(shared_ptr<Unit> target) {  //TODO smart pointer here
    Attack = target->getAttack();
    Defense = target->getDefense();
    cost = target->getCost();
    ability = target->getAbility();
    player = target->getPlayer();
    Action = target->hasAction();
    onBoard = target->OnBoard();
    base = target;
}

void Enchantment::die() {
    base->die();
}

void Enchantment::unsummon() {
    base->unsummon();
}

void Enchantment::disenchant() {
  player->disenchant(shared_from_this());
  if (BaseAttack > 0) Attack -= BaseAttack;
  base->setStats(Attack,Defense);
  player->placeEnchantment(base);
  if (BaseDefense > 0) base->getHit(BaseDefense);
}

//Accessors---------------------------------------------------------------------

Card::CardType Enchantment::getType() const {
    if (base) return Card::MINION;
    return Card::ENCHANTMENT;
}

string Enchantment::getName() const {
  if (base) return base->getName();
  else return getEnchantmentName();
}

string Enchantment::getDescription() const {
    if (base) return base->getDescription();
    else return getEnchantmentDescription();
}

shared_ptr<Unit> Enchantment::getBase() {
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
void GiantStrength::enchant(shared_ptr<Unit> target) {
    Attack = target->getAttack() + 2;
    Defense = target->getDefense() + 2;
    cost = target->getCost();
    ability = target->getAbility();
    player = target->getPlayer();
    Action = target->hasAction();
    onBoard = target->OnBoard();
    base = target;
}

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
Ability::AbilityType Silence::checkAbility() const {
    return Ability::SILENCE;
}

// Aura
Aura::Aura(Player* player) : Enchantment{2,-1,-1,player} {
    addAbility("Aura_Ability");
}
string Aura::getEnchantmentName() const {return "Aura";}
string Aura::getEnchantmentDescription() const
{
    return "Give target minion the Aura Ability";
}

void Aura::enchant(shared_ptr<Unit> target) {
    Attack = target->getAttack();
    Defense = target->getDefense();
    cost = target->getCost();
    player = target->getPlayer();
    Action = target->hasAction();
    onBoard = target->OnBoard();
    base = target;
}

string Aura::getDescription() const {
    return ability->getDescription();
}