#include "Card.h"

Card::Card()
{
    //ctor
}

Card::~Card()
{
    //dtor
}

static Ability * getAbility(std::string ability);
static void addAbility(std::string ability);
static void initialize_Abilities();