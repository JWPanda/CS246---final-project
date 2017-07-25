#include "Ability.h"
#include <string>


// Ctor and Dtor----------------------------------------------------------------
Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}


// Accessors--------------------------------------------------------------------
int Ability::getCost () {return cost;}

void Ability::use(Board& theBoard, int p , int t, Player* myPlayer) {
    throw "Error: can't use pure ability";
}

void Ability::use(Board& theBoard, std::shared_ptr<Unit> target, Player* enemy, Player* friendly) {
    throw "Error: can't use pure ability";
}
