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
    // does death check happen here or in board??
    // occurring on the board makes trigger check easier
    // occuring on board makes die to graveyard make sense
    isDead();
    target.isDead();
}

// no longer needed since apparently we can access
// the private fields of another Unit since we are still under the Unit scope
// this method would make sense if we implemented spells that do damage

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

int Unit::getAttack() { return Attack; }
int Unit::getDefense() { return Defense; }

