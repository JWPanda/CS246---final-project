#include "Card.h"
using namespace std;



//Ctor and Dtor:----------------------------------------------------------------
Card::Card(Player* owner, int cost) : player{owner}, cost{cost} {}

Card::~Card() {}



//Game Mechanics----------------------------------------------------------------

void Card::use(Board& theBoard, int p, t) {
    if(!ability) throw;
    if(ability->isTriggered() == 0) ability->use(theBoard, p, t,player);
    else ability->use(theBoard, theBoard.gettarget, target.player, player);
}


// List of Abilities initialization:--------------------------------------------
std::map<std::string, std::shared_ptr<Ability>> Card::listOfAbilities;



// Ability Implementation-------------------------------------------------------
void Card::initializeAbilities() {
    // Active Minion Abilities
    listOfAbilities["NovicePyromancer_Ability"] = make_shared<NovicePyromancer_Ability>();
    listOfAbilities["ApprenticeSummoner_Ability"] = make_shared<ApprenticeSummoner_Ability>();
    listOfAbilities["MasterSummoner_Ability"] = make_shared<MasterSummoner_Ability>();

    // Triggered Minion Abilities
    //listOfAbilities["FireElemental_Ability"] = make_shared<FireElemental_Ability>();
    //listOfAbilities["PotionSeller_Ability"] = make_shared<PotionSeller_Ability>();
    //listOfAbilities["Troll_Ability"] = make_shared<Troll_Ability>();

    // Spell Abilities

    // Ritual Abilities

}

bool Card::hasAbility() const {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() const {
    //return ability->getCost();
    return 0;
}

void Card::addAbility(string name) {
    ability = listOfAbilities[name];
}



//Accessors---------------------------------------------------------------------
int Card::getCost() const {
  return cost;
}

int Card::isTriggered() const {
    if (hasAbility()) return ability->isTriggered();
    else return false;
}

int Card::getCharges() const {
  return -1;
}

string Card::getDescription() const {
    return ability->getDescription();
}

int Card::getAttack() const {
  return -1;
}

int Card::getDefense() const {
  return -1;
}


 // Enchantment Implementation--------------------------------------------------
string Card::getEnchantmentDescription() {return "";}
int Card::getEnchantmentAttack() {return -1;}
int Card::getEnchantmentDefense() {return -1;};
