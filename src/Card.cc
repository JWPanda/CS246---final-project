#include "Card.h"


using namespace std;

Card::~Card()
{
    //dtor
}

Card::Card(int cost, Player* player) : cost{cost}, player{player} {}

void Card::use(Board& theBoard, int p, int t) {
    // if (no ability) throw exception

    // use ability
    // ability->use(theBoard, p, t);
    ability->use(theBoard,p,t);
}

void Card::attack (Unit &target) {}

bool Card::hasAbility() {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() {
    return ability->getCost();
}

bool Card::isTriggered() {
    if (hasAbility()) return ability->isTriggered();
    else return false;
}

string Card::getDescription() {
    return ability->getDescription();
}


void Card::addAbility(string name) {
    ability = listOfAbilities[name];
}

void Card::initializeAbilities() {

    // Active Minion Abilities
    listOfAbilities["NovicePyromancer_Ability"] = make_shared<NovicePyromancer_Ability>();
    listOfAbilities["ApprenticeSummoner_Ability"] = make_shared<ApprenticeSummoner_Ability>();
    listOfAbilities["MasterSummoner_Ability"] = make_shared<MasterSummoner_Ability>();

    // Triggered Minion Abilities
    listOfAbilities["FireElemental_Ability"] = make_shared<FireElemental_Ability>();
    listOfAbilities["PotionSeller_Ability"] = make_shared<PotionSeller_Ability>();
    listOfAbilities["Troll_Ability"] = make_shared<Troll_Ability>();

    // Spell Abilities

    // Ritual Abilities
}
