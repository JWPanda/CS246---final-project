#include "Ability.h"



// Ctor and Dtor----------------------------------------------------------------
Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}


// Accessors--------------------------------------------------------------------
int Ability::getCost () {return cost;}

void Ability::use(Board& theBoard, int p , int t, Player* myPlayer) {
    throw "invalid use call";
}

void Ability::use(Board& theBoard, int p, int t) {
    throw "invalid use call";
}
