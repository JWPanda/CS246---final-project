  #include "Ability.h"



// Ctor and Dtor----------------------------------------------------------------
Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}


// Accessors--------------------------------------------------------------------
int Ability::getCost () {return cost;}
