#include "TextDisplay.h"
#include <string>
#include <iostream>

TextDisplay::TextDisplay(Board *b) : board{b} {}

void TextDisplay::notify()
{
	this->displayBoard();
}

card_template_t TextDisplay::getCardTemplate(Card* c)
{
	if (c->getType() == MINION)
	{
		if (c->hasAbility)
		{
			if (c->isTriggered < 0)
			{
				return display_minion_triggered_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense(), c->getDescription());
			}
			return display_minion_activated_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense(), c->getCost(), c->getDescription());
		}
		return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	}
	else if (c->getType() == SPELL) return display_spell(c->getName(), c->getCost(), c->getDescription());
	else if (c->getType() == RITUAL) return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	else if (c->getType() == ENCHANTMENT) return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	else if (c->getType() == FACE) return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	else throw "THERE'S SOME WEIRD SHIT GOING DOWN";
}

void TextDisplay::printField(vector<Card*> field)
{
	// Player 1 Field
	vector<card_template_t> field_output; // Output of each card in field
	unsigned int numEmpty = 5 - field_output.size();
	for (Card* c : field) // Make templates for cards
	{
		card_template_t card = getCardTemplate(c);
		field_output.push_back(card);
	}
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field_output)
		{
			cout << minion[i];
		}
		for (unsigned int j = 0; j < numEmpty; ++j)
		{
			cout << CARD_TEMPLATE_EMPTY[j];
		}
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}
}

void TextDisplay::displayCard()
{
	return;
}

void TextDisplay::displayHand()
{
	Player* p = board->getActivePlayer();
	const vector<Card*> &hand = p->getHand();
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
	Card* grave1 = board->p1.getGraveyard(); // Get grave
	Card* ritual1 = board->p1.getRitual(); // Get ritual
	Face* face1 = board->p1.getFace(); // Get face
	card_template_t grave1_output;
	if (grave1) grave1_output = getCardTemplate(grave1);
	card_template_t ritual1_output;
	if (ritual1) ritual1_output = display_ritual(ritual1->getName(), ritual1->getCost(),
		ritual1->getAbilityCost(), ritual1->getDescription(), ritual1->getCharges());
	card_template_t player1_output = display_player_card(1, face1->getName(), face1->getDefense(), face1->getCurrentMana());
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << player1_output[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << ((grave1) ? grave1_output[i] : CARD_TEMPLATE_BORDER[i])
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	vector<Card*> field1 = board->p1.getField(); // Get field
	printField(field1);

	for (string s : CENTRE_GRAPHIC) cout << s << endl; // Centre Graphic

	// Player 2 Field
	vector<Card*> field2 = board->p2.getField(); // Get field
	printField(field2);

	// Player 1 Deck Player and Graveyard
	Card* grave2 = board->p2.getGraveyard(); // Get grave
	Card* ritual2 = board->p2.getRitual(); // Get ritual
	Face* face2 = board->p2.getFace(); // Get face
	card_template_t grave2_output;
	if (grave2) grave2_output = getCardTemplate(grave2);
	card_template_t ritual2_output;
	if (ritual2) ritual2_output = display_ritual(ritual2->getName(), ritual2->getCost(),
		ritual2->getAbilityCost(), ritual2->getDescription(), ritual2->getCharges());
	card_template_t player2_output = display_player_card(1, face2->getName(), face2->getDefense(), face2->getCurrentMana());
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
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
