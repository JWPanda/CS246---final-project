#include "TextDisplay.h"
#include <string>
#include <iostream>
#include <sstream>

TextDisplay::TextDisplay(Board *b, bool lit) : board{b}, lit{lit} {}

void TextDisplay::notify()
{
	this->displayBoard();
}

card_template_t TextDisplay::getCardTemplate(const shared_ptr<Card> c)
{
	if (c->getType() == Card::MINION)
	{
		if (c->checkAbility() != Ability::NONE)
		{
			if (c->checkAbility() != Ability::ACTIVE)
			{
				return display_minion_triggered_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense(), c->getDescription());
			}
			return display_minion_activated_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense(), c->getAbilityCost(), c->getDescription());
		}
		return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	}
	else if (c->getType() == Card::SPELL) return display_spell(c->getName(), c->getCost(), c->getDescription());
	else if (c->getType() == Card::RITUAL) return display_ritual(c->getName(), c->getCost(), c->getAbilityCost(), c->getDescription(), c->getCharges());
	else if (c->getType() == Card::ENCHANTMENT)
	{
		if (c->getEnchantmentAttack() < 0) return display_enchantment(c->getName(), c->getEnchantmentCost(), c->getEnchantmentDescription());
		stringstream ss1, ss2;
		ss1 << "+" << c->getEnchantmentAttack();
		ss2 << "+" << c->getEnchantmentDefense();
		return display_enchantment_attack_defence(c->getName(), c->getEnchantmentCost(), c->getEnchantmentDescription(), ss1.str(), ss2.str());
	}
	else if (c->getType() == Card::FACE) return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	else throw "Weird card encountered in Text Display that cannot be displayed >_<"s;
}

void TextDisplay::printField(vector<shared_ptr<Card>> field)
{
	vector<card_template_t> field_output; // Output of each card in field
	for (shared_ptr<Card> c : field) // Make templates for cards
	{
		card_template_t card = getCardTemplate(c);
		field_output.push_back(card);
	}
	unsigned int numEmpty = 5 - field_output.size();
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field_output)
		{
			cout << minion[i];
		}

		for (unsigned int j = 0; j < numEmpty; ++j)
		{
			cout << CARD_TEMPLATE_BORDER[i];
		}

		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}
}

void TextDisplay::displayCard(int i)
{
	Player *p = board->getActivePlayer();
	const vector<shared_ptr<Card>> &field = p->getField();
	shared_ptr<Card> c = field[i];
	card_template_t minion_output = getCardTemplate(c);
	for (auto line : minion_output)
	{
		cout << line << endl;
	}

	if (c->getBase())
	{
		vector<shared_ptr<Card>> enchantments;
		enchantments.push_back(c->getBase());
		while (enchantments.back()->getBase())
		{
			enchantments.push_back(enchantments.back()->getBase());
		}
		enchantments.pop_back();
		vector<card_template_t> enchantments_output;

		for (auto e : enchantments)
		{
			enchantments_output.push_back(getCardTemplate(e));
		}

		for (unsigned int i = 0; i < enchantments_output.size(); i += 5)
		{
			for (unsigned int j = 0; j < CARD_TEMPLATE_BORDER.size(); ++j)
			{
				for (unsigned int k = 0; k < 5 && i+k < enchantments_output.size(); ++k)
				{
					cout << enchantments_output[i+k][j];
				}
				cout << endl;
			}
		}
	}
}

void TextDisplay::displayHand()
{
	Player* p = board->getActivePlayer();
	const vector<shared_ptr<Card>> &hand = p->getHand();
	vector<card_template_t> hand_output; // Output of each card in hand
	for (auto c : hand) // Make templates for cards
	{
		card_template_t card = getCardTemplate(c);
		hand_output.push_back(card);
	}
	for (unsigned int i = 0; i < CARD_TEMPLATE_EMPTY.size(); ++i) // Print templates
	{
		for (auto card : hand_output)
		{
			cout << card[i];
		}
		cout << endl;
	}
}

void TextDisplay::displayBoard()
{
	// Top border
	for (int i = 0; i < 167; ++i) cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	cout << endl;

	// Player 1 Deck Player and Graveyard
	const shared_ptr<Card> grave1 = board->getPlayer(1)->getGraveyard(); // Get grave
	const shared_ptr<Card> ritual1 = board->getPlayer(1)->getRitual(); // Get ritual
	shared_ptr<Face> face1 = board->getPlayer(1)->getFace(); // Get face
	card_template_t grave1_output;
	if (grave1) grave1_output = getCardTemplate(grave1);
	card_template_t ritual1_output;
	if (ritual1) ritual1_output = display_ritual(ritual1->getName(), ritual1->getCost(),
		ritual1->getAbilityCost(), ritual1->getDescription(), ritual1->getCharges());
	string player1Name = (board->getPlayer(1) == board->getActivePlayer()) ? face1->getName() + "(Active)" : face1->getName();
	card_template_t player1_output = display_player_card(1, player1Name, face1->getDefense(), face1->getCurrentMana());
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << ((ritual1) ? ritual1_output[i] : CARD_TEMPLATE_BORDER[i])
			 << CARD_TEMPLATE_EMPTY[i]
			 << player1_output[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << ((grave1) ? grave1_output[i] : CARD_TEMPLATE_BORDER[i])
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	vector<shared_ptr<Card>> field1 = board->getPlayer(1)->getField(); // Get field
	printField(field1);

	vector<string> centre_graphic = getCentreGraphic(lit);
	for (string s : centre_graphic) cout << s << endl; // Centre Graphic

	// Player 2 Field
	vector<shared_ptr<Card>> field2 = board->getPlayer(2)->getField(); // Get field
	printField(field2);

	// Player 1 Deck Player and Graveyard
	const shared_ptr<Card> grave2 = board->getPlayer(2)->getGraveyard(); // Get grave
	const shared_ptr<Card> ritual2 = board->getPlayer(2)->getRitual(); // Get ritual
	shared_ptr<Face> face2 = board->getPlayer(2)->getFace(); // Get face
	card_template_t grave2_output;
	if (grave2) grave2_output = getCardTemplate(grave2);
	card_template_t ritual2_output;
	if (ritual2) ritual2_output = display_ritual(ritual2->getName(), ritual2->getCost(),
		ritual2->getAbilityCost(), ritual2->getDescription(), ritual2->getCharges());
	string player2Name = (board->getPlayer(2) == board->getActivePlayer()) ? face2->getName() + "(Active)" : face2->getName();
	card_template_t player2_output = display_player_card(1, player2Name, face2->getDefense(), face2->getCurrentMana());
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << ((ritual2) ? ritual2_output[i] : CARD_TEMPLATE_BORDER[i])
			 << CARD_TEMPLATE_EMPTY[i]
			 << player2_output[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << ((grave2) ? grave2_output[i] : CARD_TEMPLATE_BORDER[i])
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Bottom border
	for (int i = 0; i < 167; ++i) cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	cout << endl;
}
