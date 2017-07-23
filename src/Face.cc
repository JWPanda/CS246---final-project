#include "Face.h"

using namespace std;

Face::Face(string Name, Player* player)
 : Unit{0,0,30,player}, name{Name}, mana_cur{3}, mana_cap{3} {}

Face::~Face() {}

void Face::refillMana() {
    mana_cur = mana_cap;
}

void Face::incMana() {
    ++mana_cap;
}

int Face::getCurrentMana() { return mana_cur;}

void Face::spendMana(int cost) { mana_cur -= cost;}

void Face::die() {
    // let player know that you are dead. game over
}

int Face::getType() {
  return -1;
}

string Face::getName() {
    return name;
}
