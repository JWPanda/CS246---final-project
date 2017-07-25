#include "Unit.h"

using namespace std;

// ctor does card need a name field?
Unit::Unit(int cost, int Attack, int Defense, Player* player)
 : Card{player, cost}, Attack{Attack}, Defense{Defense},
   BaseAttack{Attack}, BaseDefense{Defense} {}

Unit::~Unit() {}

void Unit::attack(Unit& target) {
    target.Defense -= Attack;
    Defense -= target.Attack;
    isDead();
    target.isDead();
}

void Unit::getHit(int attack) {
    Defense -= attack;
    isDead();
}

void Unit::reduceAttack(int i) {
    Attack -= i;
}

void Unit::isDead() {
    if (Defense <= 0) die();
};

int Unit::getAttack() const { return Attack; }
int Unit::getDefense() const { return Defense; }
