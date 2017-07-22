#include "TextDisplay.h"
#include <string>

TextDisplay::TextDisplay(Board *b) : board{b} {}

void TextDisplay::notify()
{
	this->displayBoard();
}

card_template_t TextDisplay::getCardTemplate(Card* c)
{
	if (c->getType() == MINION) return display_minion_no_ability(c->getName(), c->getCost(), c->getAttack(), c->getDefense());
	// else if (c->getType() == )
}

void TextDisplay::displayCard()
{
	return;
}

void TextDisplay::displayHand()
{
	Player* p = board->getActivePlayer();
	vector<Card*> hand = p->getHand();
	vector<card_template_t> hand_output; // Output of each card in hand
	for (Card* c : hand) // Make templates for cards
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
	Card& grave = board->p1.getGraveyard(); // Get grave
	card_template_t graveOutput;
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << PLAYER_1_TEMPLATE[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << CARD_TEMPLATE_BORDER[i]
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Player 1 Field
	vector<Card*> field1 = board->p1.getField(); // Get hand
	vector<card_template_t> field_output1; // Output of each card in field
	for (Card* c : field1) // Make templates for cards
	{
		card_template_t card = getCardTemplate(c);
		field_output1.push_back(card);
	}
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field_output1)
		{
			cout << minion[i];
		}
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	for (string s : CENTRE_GRAPHIC) cout << s << endl; // Centre Graphic

	// Player 2 Field
	vector<Card*> field2 = board->p2.getField(); // Get hand
	vector<card_template_t> field_output2; // Output of each card in field
	for (Card* c : field2) // Make templates for cards
	{
		card_template_t card = getCardTemplate(c);
		field_output2.push_back(card);
	}
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field_output2)
		{
			cout << minion[i];
		}
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Player 2 Deck Player and Graveyard
	Card& grave2 = board->p2.getGraveyard(); // Get grave
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << PLAYER_1_TEMPLATE[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << CARD_TEMPLATE_BORDER[i]
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Bottom border
	for (int i = 0; i < 167; ++i) cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	cout << endl;
}
