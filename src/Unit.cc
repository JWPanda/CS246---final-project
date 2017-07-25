#include "Unit.h"

using namespace std;

// ctor does card need a name field?
Unit::Unit(int cost, int Attack, int Defense, Player* player)
 : Card{player, cost}, Attack{Attack}, Defense{Defense},
   BaseAttack{Attack}, BaseDefense{Defense}, Action{true}, OnBoard{false} {}

Unit::~Unit() {}

void Unit::attack(shared_ptr<Unit> target) {
    //if (Action == false) throw "Minion has already attacked this turn"s;
    Action = false;
    target->Defense -= Attack;
    Defense -= target->Attack;
    isDead();
    target->isDead();
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
