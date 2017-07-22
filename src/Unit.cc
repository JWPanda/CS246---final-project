#include "Unit.h"

using namespace std;


Unit::~Unit()
{
    //dtor
}

// ctor

// ctor does card need a name field?
Unit::Unit(int cost, int Attack, int Defense, Player* player)
 : Card{cost, player}, Attack{Attack}, Defense{Defense},
   BaseAttack{Attack}, BaseDefense{Defense} {}


int Unit::getAttack() { return Attack; }
int Unit::getDefense() { return Defense; }

void Unit::attack(Unit& target) {
    target.Defense -= Attack;
    Defense -= target.Attack;
    // does death check happen here or in board??
    // occurring on the board makes trigger check easier
    // occuring on board makes die to graveyard make sense
    isDead();
    target.isDead();
}

void Unit::isDead() {
    if (Defense <= 0) die();
};

// no longer needed since apparently we can access
// the private fields of another Unit since we are still under the Unit scope
// this method would make sense if we implemented spells that do damage
void Unit::getHit(int attack) {}


// not sure about these implementations...
// need to send in face to use the magic?


