<<<<<<< HEAD
  #include "Ability.h"



// Ctor and Dtor----------------------------------------------------------------
Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}


// Accessors--------------------------------------------------------------------
int Ability::getCost () {return cost;}
=======
#include "Ability.h"

Ability::Ability(int cost) : cost{cost} {}

Ability::~Ability() {}

int Ability::getCost () {return cost;}
>>>>>>> dc5a43d04d513daa015b55d909cc801584ee9709
