#include "Ability.h"

Ability::~Ability()
{
    //dtor
}

Ability::Ability(int cost) : cost{cost} {}

Ability::getCost() { return cost;}
