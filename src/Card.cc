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

//void Card::attack(Unit& target) {}


int Card::getCost() { return cost;}

int Card::getAttack() { return -1;}
int Card::getDefense() { return -1;}

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
    if (ability) return ability->isTriggered();
    else return -1;

void Card::addAbility(string name) {
    //ability = listOfAbilities[name];
}

int Card::getCost() {
  return cost;
}

/*
bool Card::isTriggered() {
>>>>>>> refs/remotes/origin/master
    if (hasAbility()) return ability->isTriggered();
    else return false;
}
*/

string Card::getDescription() {
    return ability->getDescription();
}


void Card::addAbility(string name) {
    ability = Card::listOfAbilities[name];
}

void Card::initializeAbilities() {

    // Active Minion Abilities
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("NovicePyromancer_Ability", make_shared<NovicePyromancer_Ability>());
    Card::listOfAbilities.insert(pair<string,shared_ptr<Ability>>("ApprenticeSummoner_Ability", make_shared<ApprenticeSummoner_Ability>());
    Card::listOfAbilities.insert(pair<string,Ability>("MasterSummoner_Ability", make_shared<MasterSummoner_Ability>());

    // Triggered Minion Abilities
    listOfAbilities.insert(pair<string,shared_ptr<Ability>>"FireElemental_Ability", make_shared<FireElemental_Ability>());
    listOfAbilities.insert(pair<string,shared_ptr<Ability>>("PotionSeller_Ability", make_shared<PotionSeller_Ability>());
    listOfAbilities.insert(pair<string,shared_ptr<Ability>>("Troll_Ability", make_shared<Troll_Ability>());

    // Spell Abilities

    // Ritual Abilities

}


 // Enchantment Implementation
string Card::getEnchantmentDescription() {return "";}
int Card::getEnchantmentAttack() {return -1;}
int Card::getEnchantmentDefense() {return -1;};
string Card::getEnchantmentName() { return "";}
