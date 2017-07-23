#include "Ability.h"

Ability::~Ability()
{
    //dtor
}

Ability::Ability(int cost) : cost{cost} {}

int Ability::getCost() { return cost};
