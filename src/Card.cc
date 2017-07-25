#include "Card.h"
using namespace std;



//Ctor and Dtor:----------------------------------------------------------------
Card::Card(Player* owner, int cost) : player{owner}, cost{cost} {}

Card::~Card() {}


//Game Mechanics----------------------------------------------------------------
void Card::use(Board& theBoard, int p, int t) {
    if(!ability) throw "Error: this card does not have an ability"s;
    if(ability->isTriggered() == 0) ability->use(theBoard, p, t, player);
  //TODO else ability->use(theBoard, theBoard.gettarget, target.player, player);
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
    listOfAbilities["FireElemental_Ability"] = make_shared<FireElemental_Ability>();
    listOfAbilities["PotionSeller_Ability"] = make_shared<PotionSeller_Ability>();
    listOfAbilities["Troll_Ability"] = make_shared<Troll_Ability>();

    // Spell Abilities
    listOfAbilities["Banish_Ability"] = make_shared<Banish_Ability>();
    listOfAbilities["Unsummon_Ability"] = make_shared<Unsummon_Ability>();
    listOfAbilities["Recharge_Ability"] = make_shared<Recharge_Ability>();
    listOfAbilities["Disenchant_Ability"] = make_shared<Disenchant_Ability>();
    listOfAbilities["RaiseDead_Ability"] = make_shared<RaiseDead_Ability>();
    listOfAbilities["Blizzard_Ability"] = make_shared<Blizzard_Ability>();

    // Ritual Abilities
    listOfAbilities["DarkRitual_Ability"] = make_shared<DarkRitual_Ability>();
    listOfAbilities["AuraOfPower_Ability"] = make_shared<AuraOfPower_Ability>();
    listOfAbilities["Standstill_Ability"] = make_shared<Standstill_Ability>();
}

bool Card::hasAbility() const {
    if(ability) return true;
    else return false;
}

int Card::getAbilityCost() const {
    if(ability) return ability->getCost();
    return 0;
}

void Card::addAbility(string name) {
    ability = listOfAbilities[name];
}

void Card::unsummon() {
    return;
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

Unit* Card::getBase() {
    return nullptr;
}


 // Enchantment Implementation--------------------------------------------------
string Card::getEnchantmentName() const {return "";}
string Card::getEnchantmentDescription() const {return "";}
std::shared_ptr<Ability> Card::getAbility() {return ability;}
int Card::getEnchantmentCost() const {return -1;}
int Card::getEnchantmentAttack() const {return -1;}
int Card::getEnchantmentDefense() const {return -1;};
