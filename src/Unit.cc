#include "Unit.h"

using namespace std;

// ctor does card need a name field?
Unit::Unit(int cost, int Attack, int Defense, Player* player)
 : Card{player, cost}, Attack{Attack}, Defense{Defense},
   BaseAttack{Attack}, BaseDefense{Defense}, Action{true}, onBoard{false} {}

Unit::~Unit() {}

void Unit::use(Board& theBoard, int p, int t) {
  if(!Action) throw getName() + " can no longer act this turn"s;
  Card::use(theBoard, p, t);
  Action = false;
}

void Unit::attack(shared_ptr<Unit> target) {
    if(!Action) throw getName() + " can no longer act this turn"s;
    Action = false;
    target->Defense -= Attack;
    Defense -= target->Attack;
    isDead();
    target->isDead();
}

void Unit::grantAction() { Action = true;}

void Unit::getHit(int attack) {
    Defense -= attack;
    isDead();
}

void Unit::setStats(int atk, int def) {
  Attack = atk;
  Defense = def;
}

void Unit::isDead() {
    if (Defense <= 0) die();
};

void Unit::disenchant() {
  throw getName() + "Cannot be disenchanted"s;
}

void Unit::gainStats(int atk, int def){
  Attack += atk;
  Defense += def;
}


bool Unit::OnBoard() const { return onBoard;}
bool Unit::hasAction() const {return Action;}
int Unit::getAttack() const { return Attack; }
int Unit::getDefense() const { return Defense; }
