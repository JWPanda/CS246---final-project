#include "Ability.h"

Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}

int Ability::getCost () {return cost;}

