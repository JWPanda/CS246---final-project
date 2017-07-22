#include "textdisplay.h"
#include <string>

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
	Player* p = board.getActivePlayer();
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
			cout << hand_output[i];
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
	Card& grave = board->p1->getGraveyard(); // Get grave
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << PLAYER_1_TEMPLATE[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << grave[i]
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Player 1 Field
	vector<Card*> field = board->p1->getField(); // Get hand
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field)
		{
			cout << minion[i];
		}
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	for (string s : CENTRE_GRAPHIC) cout << s << endl; // Centre Graphic

	// Player 2 Field
	vector<Card*> field = board->p2->getField(); // Get hand
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for (auto minion : field)
		{
			cout << minion[i];
		}
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Player 2 Deck Player and Graveyard
	Card& grave = board->p2->getGraveyard(); // Get grave
	for (unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); ++i)
	{
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << CARD_TEMPLATE_BORDER[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << PLAYER_1_TEMPLATE[i]
			 << CARD_TEMPLATE_EMPTY[i]
			 << grave[i]
			 << EXTERNAL_BORDER_CHAR_UP_DOWN
			 << endl;
	}

	// Bottom border
	for (int i = 0; i < 167; ++i) cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	cout << endl;
}
