#include "Face.h"
#include "Player.h"

using namespace std;

Face::Face(string Name, Player* player)
 : Unit{0,0,20,player}, name{Name}, mana_cur{3}, mana_cap{3} {}

Face::~Face() {}

void Face::play (Board &theBoard, int i, int p, int t ) {}

void Face::refillMana() {
    mana_cur = mana_cap;
}

void Face::incMana() {
    ++mana_cap;
}

void Face::gainMana(int m) {
  mana_cur +=m;
}

int Face::getCurrentMana() const { return mana_cur;}

void Face::spendMana(int cost) { mana_cur -= cost;}

void Face::die() {
    // Let main know that you are dead. game over
    throw player->getNumber();
}

Card::CardType Face::getType() const {return FACE;}

string Face::getName() const {
    return name;
}
