#include "Ability.h"

Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}

int Ability::getCost () {return cost;}

void Ability::use(Board& theBoard, Unit * target, Player* myPlayer) {
    throw "invalid use call";
    return;
}
void Ability::use(Board& theBoard, Unit * target, Player* targetPlayer, Player* myPlayer) {
    throw "invalid use call";
    return;
}
