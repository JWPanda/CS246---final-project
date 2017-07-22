#include "Card.h"

using namespace std;

Card::Card()
{
    //ctor
}

Card::~Card()
{
    //dtor
}

Card::Card(int cost) : cost{cost} {}


void Card::use(Board& theBoard, int p =-1, int t = -1) {
    // if (no ability) throw exception

    // use ability
    // ability->use(theBoard, p, t);
    ability->use(theBoard,p,t)
}

bool Card::hasAbility() {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() {
    return ability->getCost();
}

std::string Card::getDescription() {
    return ability->getDescription();
}


void Card::addAbility(string name) {
    ability = listOfAbilities[name];
}

static void Card::initialize_Abilities() {

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
}
