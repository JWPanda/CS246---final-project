#include "Factory.h"
#include <iostream>

using namespace std;

Factory::Factory() {}

Factory::~Factory() {}

Card* Factory::makeCard(string cardname, Player* owner) {
  //Make Minions:
  if (cardname == "Air Elemental") return (new AirElemental(owner));
  else if (cardname == "Earth Elemental") return (new EarthElemental(owner));
  else if (cardname == "Fire Elemental") return (new FireElemental(owner));
  else if (cardname == "Potion Seller") return (new PotionSeller(owner));
  else if (cardname == "Novice Pyromancer") return (new NovicePyromancer(owner));
  else if (cardname == "Apprentice Summoner") return (new ApprenticeSummoner(owner));
  else if (cardname == "Master Summoner") return (new MasterSummoner(owner));
  else if (cardname == "Troll") return (new Troll(owner));
  /* TODO
  //Make Spells:
  else if (cardname == "Banish") return (new Banish(owner));
  else if (cardname == "Unsummon") return (new Unsummon(owner));
  else if (cardname == "Recharge") return (new Recharge(owner));
  else if (cardname == "Disenchant") return (new Disenchant(owner));
  else if (cardname == "Raise Dead") return (new RaiseDead(owner));
  else if (cardname == "Blizzard") return (new Blizzard(owner));
  //Enchantment:
  else if (cardname == "Giant Strength") return (new GiantStrength(owner));
  else if (cardname == "Magic Fatigue") return (new MagicFatigue(owner));
  else if (cardname == "Silence") return (new Silence(owner));
  //Rituals:
  */
  else if (cardname == "Dark Ritual") return (new DarkRitual(owner));
  else if (cardname == "Aura of Power") return (new AuraOfPower(owner));
  else if (cardname == "Standstill") return (new Standstill(owner));
  else throw;
}
