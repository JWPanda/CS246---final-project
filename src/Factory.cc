#include "Factory.h"
#include <iostream>

using namespace std;

Factory::Factory() {}

Factory::~Factory() {}

shared_ptr<Card> Factory::makeCard(string cardname, Player* owner) {
  //Make Minions:
  if (cardname == "Air Elemental") return (make_shared<AirElemental>(owner));
  else if (cardname == "Earth Elemental") return (make_shared<EarthElemental>(owner));
  else if (cardname == "Fire Elemental") return (make_shared<FireElemental>(owner));
  else if (cardname == "Potion Seller") return (make_shared<PotionSeller>(owner));
  else if (cardname == "Novice Pyromancer") return (make_shared<NovicePyromancer>(owner));
  else if (cardname == "Apprentice Summoner") return (make_shared<ApprenticeSummoner>(owner));
  else if (cardname == "Master Summoner") return (make_shared<MasterSummoner>(owner));
  else if (cardname == "Troll") return (make_shared<Troll>(owner));
  //Make Spells:
  else if (cardname == "Banish") return (make_shared<Banish>(owner));
  else if (cardname == "Unsummon") return (make_shared<Unsummon>(owner));
  else if (cardname == "Recharge") return (make_shared<Recharge>(owner));
  else if (cardname == "Disenchant") return (make_shared<Disenchant>(owner));
  else if (cardname == "Raise Dead") return (make_shared<RaiseDead>(owner));
  else if (cardname == "Blizzard") return (make_shared<Blizzard>(owner));
  //Enchantment:
  else if (cardname == "Giant Strength") return (make_shared<GiantStrength>(owner));
  else if (cardname == "Magic Fatigue") return (make_shared<MagicFatigue>(owner));
  else if (cardname == "Silence") return (make_shared<Silence>(owner));
  //Rituals:
  else if (cardname == "Dark Ritual") return (make_shared<DarkRitual>(owner));
  else if (cardname == "Aura of Power") return (make_shared<AuraOfPower>(owner));
  else if (cardname == "Standstill") return (make_shared<Standstill>(owner));
  else throw "Invalid card '"s + cardname + "' found in deck! Exiting..."s;
}
