#include "Card.h"
using namespace std;

Card::Card(Player* owner, int cost) : player{owner}, cost{cost} {}

Card::~Card() {}

/* TODO
void Card::use(Board& theBoard, int p, int t) {
    // if (no ability) throw exception

    // use ability
    // ability->use(theBoard, p, t);
    ability->use(theBoard,p,t)
}
*/

void Card::initializeAbilities() {
/* TODO~~~~~~~~~~~~
    // Active Minion Abilities
    listOfAbilities["NovicePyromancer_Ability"] = make_shared<Ability>(NovicePyromancer_Ability());
    listOfAbilities["ApprenticeSummoner_Ability"] = make_shared<Ability>(ApprenticeSummoner_Ability());
    listOfAbilities["MasterSummoner_Ability"] = make_shared<Ability>(MasterSummoner_Ability());

    // Triggered Minion Abilities
    listOfAbilities["FireElemental_Ability"] = make_shared<Ability>(FireElemental_Ability());
    listOfAbilities["PotionSeller_Ability"] = make_shared<Ability>(PotionSeller_Ability());
    listofAbilities["Troll_Ability"] = make_shared<Ability>(Troll_Ability());

    // Spell Abilities

    // Ritual Abilities
    */
}

bool Card::hasAbility() {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() {
    //return ability->getCost();
    return 0;
}

void Card::addAbility(string name) {
    //ability = listOfAbilities[name];
}

int Card::getCost() {
  return cost;
}

/*
bool Card::isTriggered() {
    if (hasAbility()) return ability->isTriggered();
    else return false;
}
*/

string Card::getDescription() {
    return ability->getDescription();
}

int Card::getAttack() {
  return -1;
}

int Card::getDefense() {
  return -1;
}
