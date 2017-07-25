#include "Card.h"
#include "Unit.h"
using namespace std;



//Ctor and Dtor:----------------------------------------------------------------
Card::Card(Player* owner, int cost) : player{owner}, cost{cost} {}

Card::~Card() {}


//Game Mechanics----------------------------------------------------------------
void Card::use(Board& theBoard, int p, int t) {
    if(!ability) throw "Error: this card does not have an ability"s;
    if (checkAbility() == Ability::SILENCE) throw "Error: this card is silenced"s;
    if(ability->checkAbility() != Ability::NONE) ability->use(theBoard, p, t);

}

void Card::use(Board& theBoard, shared_ptr<Unit> target) {
  if(!ability) return;
  Player * enemy = nullptr;
  if (target) enemy = target->getPlayer();
  ability->use(theBoard, target, enemy, player);
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

Ability::AbilityType Card::checkAbility() const {
    if(!ability) return Ability::NONE;
    else return ability->checkAbility();
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
Player* Card::getPlayer() {
  return player;
}

int Card::getCost() const {
  return cost;
}

int Card::getCharges() const {
  return -1;
}

string Card::getDescription() const {
    if (!ability) return "";
    return ability->getDescription();
}

int Card::getAttack() const {
  return -1;
}

int Card::getDefense() const {
  return -1;
}

shared_ptr<Unit> Card::getBase() {
    return nullptr;
}


 // Enchantment Implementation--------------------------------------------------
string Card::getEnchantmentName() const {return "";}
string Card::getEnchantmentDescription() const {return "";}
std::shared_ptr<Ability> Card::getAbility() {return ability;}
int Card::getEnchantmentCost() const {return -1;}
int Card::getEnchantmentAttack() const {return -1;}
int Card::getEnchantmentDefense() const {return -1;};
