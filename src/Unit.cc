#include "Unit.h"

using namespace std;

// ctor does card need a name field?
Unit::Unit(int cost, int Attack, int Defense, Player* player)
 : Card{player, cost}, Attack{Attack}, Defense{Defense},
   BaseAttack{Attack}, BaseDefense{Defense}, Action{true}, onBoard{false} {}

Unit::~Unit() {}

void Unit::attack(Unit& target) {
    Action = false;
    target.Defense -= Attack;
    Defense -= target.Attack;
    isDead();
    target.isDead();
}

void Unit::getHit(int attack) {
    Defense -= attack;
    isDead();
}


void Unit::isDead() {
    if (Defense <= 0) die();
};

void Unit::disenchant() {}

void Unit::gainStats(int atk, int def){
  Attack += atk;
  Defense += def;
}


bool Unit::OnBoard() const { return onBoard;}
int Unit::getAttack() const { return Attack; }
int Unit::getDefense() const { return Defense; }
