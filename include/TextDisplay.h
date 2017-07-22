#ifndef __TEXT_DISPLAY_H__
#define __TEXT_DISPLAY_H__
#include <vector>
#include <iostream>
#include "ascii_graphics.h"
#include "Observer.h"
#include "Board.h"

using namespace std;

class TextDisplay : public Observer
{
	Board* board;
	enum CardTypes { MINION, SPELL, RITUAL, ENCHANTMENT };
	card_template_t getCardTemplate(Card* c);
public:
	void notify();
	void displayBoard();
	void displayCard(const Card& c);
	void displayHand(const vector<Card*>& v);
	// void displayMinionNoAbility(std::string name,int cost,int attack,int defence);
	// void displayMinionTriggeredAbility(std::string name,int cost,int attack,int defence, std::string trigger_desc);
	// void displayMinionActivatedAbility(std::string name,int cost,int attack,int defence, int ability_cost, std::string ability_desc);
	// void displayRitual(std::string name,int cost,int ritual_cost,std::string ritual_desc, int ritual_charges);
	// void displaySpell(std::string name,int cost,std::string desc);
	// void displayEnchantmentAttackDefence(std::string name,int cost,std::string desc, std::string attack,std::string defence);
	// void displayEnchantment(std::string name,int cost,std::string desc);
	// void displayPlayerCard(int player_num,std::string name,int life,int mana);
	// void displayWeapon(std::string name,int cost,std::string attack,std::string defence);
};

#endif // TEXT_DISPLAY_H