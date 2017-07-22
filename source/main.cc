#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <ifstream>
#include "Board.h"
#include "TextDisplay.h"

using namespace std;

void showMainHelp()
{
	cout << "Commands:\n\t\thelp -- Display this message." <<
					"\n\t\tend -- End the current player’s turn." <<
					"\n\t\tquit -- End the game." <<
					"\n\t\tattack minion other-minion -- Orders minion to attack other-minion." <<
					"\n\t\tattack minion -- Orders minion to attack the opponent." <<
					"\n\t\tplay card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player." <<
					"\n\t\tuse minion [target-player target-card] -- Use minion’s special ability, optionally targeting target-card owned by target-player." <<
					"\n\t\tinspect minion -- View a minion’s card and all enchantments on that minion." <<
					"\n\t\thand -- Describe all cards in your hand." <<
					"\n\t\tboard -- Describe all cards on the board." << endl;
}

void showCommandLineHelp()
{
	cout << "Command Line Arguments: \n\t\thelp -- Display this message." <<
									"\n\t\t-testing -- Enter testing mode" <<
									"\n\t\t-init -- Enter a series of commands for the beginning of the game" <<
									"\n\t\t-deck1 -- Specify a deck file for Player 1" <<
									"\n\t\t-deck2 -- Specify a deck file for Player 2" <<
}

int main(int argc, char* argv[])
{
	TextDisplay display;
	Board board;
	Card.initializeAbilities();
	bool testing = false;
	for (int i = 0; i < argc; ++i)
	{
		try
		{
			if (string(argv[i]) == "-testing") // Check testing mode
			{
				testing = true;
			}
			else if (string(argv[i]) == "-deck1")
			{
				ifstream deck1;
				if (i != argc - 1)
				{

				}
				else throw argv[i];
			}
		}
		catch (string arg)
		{
			cout << "You do not use command line argument " << arg << " in this way." << endl;

		}
		
	}

	string input;
	while (getline(cin, input))
	{
		stringstream ss{input};
		string command;
		ss >> command;
		try
		{
			if (command == "help")
			{
				// Help command
				showHelp();
				
			else if (command == "end")
			{
				// Switch player turn
	
			}
			else if (command == "quit")
			{
				break;
			}
			else if (command == "draw")
			{
				if (!testing) // Draw can only be used in testing mode
				{
					cout << "Cannot use draw in non-testing mode. Run executable with '-testing' to access draw." << endl;
				}
				else
				{
					// Draw a card
					Player* p = board.getActivePlayer();
					p->draw();
				}
			}
			else if (command == "discard")
			{
				if (!testing) // Discard can only be used in testing mode
				{
					cout << "Cannot use discard in non-testing mode. Run executable with '-testing' to access discard." << endl;
				}
				else
				{
					// Discard a card
					// int i;
					// cin >> i;
					// Player* p = board.getActivePlayer();
					// p->draw();
				}
			}
			else if (command == "attack")
			{
				// Attack a minion
				int i;
				ss >> i;
				if (ss.fail()) throw command;
			}
			else if (command == "play")
			{
				// Play card
				int i;
				ss >> i;
				if (ss.fail()) throw command;
				int p, t;
				ss >> p;
				if (ss.fail())
				{
					board.play(i-1);
				}
				else
				{
					ss >> t;
					if (ss.fail()) throw command;
					board.play(i-1, p, t-1);
				}
			}
			else if (command == "use")
			{
				// Use card
				int i;
				ss >> i;
				if (ss.fail()) throw command;
				int p, t;
				ss >> p;
				if (ss.fail())
				{
					board.use(i-1);
				}
				else
				{
					ss >> t;
					if (ss.fail()) throw command;
					board.use(i-1, p, t-1);
				}
			}
			}
			else if (command == "inspect")
			{
				// Insepct minion
				display.inspect(i-1);
			}
			else if (command == "hand")
			{
				// Display hand
				display.displayHand();
			}
			else if (command == "board")
			{
				// Display full board
				display.displayBoard();
			}
		}
		catch (string command)
		{
			cout << "That is not how you use the " << command << "command." << endl;
			showHelp();
		}
	}
}
