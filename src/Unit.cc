#include "Unit.h"

using namespace std;

Unit::Unit()
{
    //ctor
}

Unit::~Unit()
{
    //dtor
}

// ctor
Unit::Unit(string Name) {

}

// ctor does card need a name field?
Unit(int cost,int Attack, int Defense)
 : Card{cost}, Attack{Attack}, Defense{Defense} {}


int Unit::getAttack() { return Attack; }
int Unit::getDefense() { return Defense; }

void Unit::attack(Unit& target) {
    target.Defense -= Attack;
    Defense -= target.Attack;
    // does death check happen here or in board??
    // occurring on the board makes trigger check easier
    // occuring on board makes die to graveyard make sense
}

// no longer needed since apparently we can access
// the private fields of another Unit since we are still under the Unit scope
// this method would make sense if we implemented spells that do damage
void Unit::getHit(int attack) {}

int Unit::getAbilityCost() {
    if (ability.isTriggered()) return 0;
    return ability.getCost(); // this is an active ability method
}

// not sure about these implementations...
// need to send in face to use the magic?

Unit::use(Face& player) {
    ability.use(player)
}
Unit::use(Face& player, Unit& target) {
    ability.use(player, target);
}


