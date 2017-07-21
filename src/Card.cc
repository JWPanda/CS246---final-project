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


void Card::use(Board& theBoard, int p =0, int t = 0) {
    // if (no ability) throw exception

    // use ability
    // ability->use(theBoard, p, t);
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
