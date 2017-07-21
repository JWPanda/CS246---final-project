#include "Minion.h"


Minion::~Minion()
{
    //dtor
}

Minion::Minion(int cost, int BaseAttack, int BaseDefense)
 : Unit{cost, BaseAttack, BaseDefense},
   BaseAttack{BaseAttack}, BaseDefense{BaseDefense} {}

// in order to move, we must also know both the current location and location dying to
// must reset to base stats
Unit::die(std::vector<Card*> location) {
    // reset to initial values
    attack = BaseAttack;
    Defense = BaseDefense;

    // move to next field
}

// Minion Sub classes below

AirElemental::AirElemental() : Minion{0,1,1} {}

EarthElemental::EarthElemental() : Minion{3,4,4} {}

FireElemental::FireElemental() : Minion{2,2,2} {
    // add ability here
}

PotionSeller::PotionSeller() : Minion{2,1,3} {
    // add ability here
}

NovicePyromancer::NovicePyromancer() : Minion{1,0,1} {
    // add ability here
}

ApprenticeSummoner::ApprenticeSummoner() : Minion{1,1,1} {
    // add ability here
}

MasterSummoner::MasterSummoner() : Minion{3,2,3} {
    // add ability here
}