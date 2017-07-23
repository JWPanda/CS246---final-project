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



//void Card::attack(Unit& target) {}


int Card::getCost() { return cost;}

int Card::getAttack() { return -1;}
int Card::getDefense() { return -1;}

string Card::getDescription() {
    return ability->getDescription();
}

void Card::attack(Unit& target) {}



bool Card::hasAbility() {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() {
    //return ability->getCost();
    return 0;
}


int Card::isTriggered() {
  if(ability) return ability->isTriggered();
  else return -1;
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

 void Card::initializeAbilities() {

    // Active Minion Abilities
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("NovicePyromancer_Ability", make_shared<NovicePyromancer_Ability>());
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("ApprenticeSummoner_Ability", make_shared<ApprenticeSummoner_Ability>());
    Card::listOfAbilities.insert(pair<string,Ability>("MasterSummoner_Ability", make_shared<MasterSummoner_Ability>());

    // Triggered Minion Abilities
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>"FireElemental_Ability", make_shared<FireElemental_Ability>());
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("PotionSeller_Ability", make_shared<PotionSeller_Ability>());
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("Troll_Ability", make_shared<Troll_Ability>());

    // Spell Abilities

    // Ritual Abilities
}

  




void Card::addAbility(string name) {
    ability = Card::listOfAbilities[name];
}


 // Enchantment Implementation
string Card::getEnchantmentDescription() {return "";}
int Card::getEnchantmentAttack() {return -1;}
int Card::getEnchantmentDefense() {return -1;};
string Card::getEnchantmentName() { return "";}
