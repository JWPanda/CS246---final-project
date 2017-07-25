#include "Minion.h"
#include "Player.h"

using namespace std;

//Ctor and Dtor-----------------------------------------------------------------
Minion::Minion(int cost, int Attack, int Defense, Player * player)
 : Unit{cost,Attack,Defense,player} {}

Minion::~Minion() {}


//Death Mechanics---------------------------------------------------------------
// in order to move, we must also know both the current location and location dying to
// must reset to base stats
void Minion::die() {
    // reset to initial values
    reset();

    // move to next field
    player->moveToGraveyard(shared_from_this());
}

// reset minion's attack and defense to base values
void Minion::reset() {
   Attack = BaseAttack;
   Defense = BaseDefense;
}


// Game Mechanics---------------------------------------------------------------
void Minion::play (Board& theBoard, int i, int p, int t) {
  player->moveToBoard(shared_from_this());
}

void Minion::unsummon() {
  player->moveToDeck(shared_from_this());
}


// Acessors---------------------------------------------------------------------
Card::CardType Minion::getType() const {return MINION;}


// Minion Sub classes below-----------------------------------------------------
AirElemental::AirElemental(Player * player) : Minion{0,1,1,player} {}
string AirElemental::getName() const { return "Air Elemental"; }

EarthElemental::EarthElemental(Player * player) : Minion{3,4,4,player} {}
string EarthElemental::getName() const { return "Earth Elemental"; }


FireElemental::FireElemental(Player * player) : Minion{2,2,2,player} {
    addAbility("FireElemental_Ability");
}
string FireElemental::getName() const { return "Fire Elemental"; }


PotionSeller::PotionSeller(Player * player) : Minion{2,1,3,player} {
    addAbility("PotionSeller_Ability");
}
string PotionSeller::getName() const { return "Potion Seller"; }


NovicePyromancer::NovicePyromancer(Player * player) : Minion{1,0,1,player} {
    addAbility("NovicePyromancer_Ability");
}
string NovicePyromancer::getName() const { return "Novice Pyromancer"; }


ApprenticeSummoner::ApprenticeSummoner(Player * player) : Minion{1,1,1,player} {
    addAbility("ApprenticeSummoner_Ability");
}
string ApprenticeSummoner::getName() const { return "Apprentice Summoner"; }


MasterSummoner::MasterSummoner(Player * player) : Minion{3,2,3,player} {
    addAbility("MasterSummoner_Ability");
}
string MasterSummoner::getName() const { return "Master Summoner"; }


Troll::Troll(Player * player) : Minion{2,2,3,player} {
    addAbility("Troll_Ability");
}
string Troll::getName() const { return "Troll"; }
