#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
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
									"\n\t\t-init <file> -- Enter a series of commands for the beginning of the game" <<
									"\n\t\t-deck1 <file> -- Specify a deck file for Player 1" <<
									"\n\t\t-deck2 <file> -- Specify a deck file for Player 2" <<
}

void parseCommand(TextDisplay display, Board &board, stringstream ss)
{
	string command;
	ss >> command;
	if (command == "help")
	{
		// Help command
		showHelp();
	}
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
	else if (command == "inspect")
	{
		// Inspect minion
		cout << "no" << endl;
		return;
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
	else
	{
		cout << "SUCK MY DICK" << endl;
	}
}

int main(int argc, char* argv[])
{
	bool testing = false;
	string deck1, deck2;
	ifstream initStream;
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			if (argv[i] == "-testing"s) // Check testing mode
			{
				testing = true;
			}
			else if (argv[i] == "-init"s)
			{
				// Pass commands in file to std::cin to be parsed in lower loop
				if (i != argc - 1)
				{
					string fileName = argv[i+1];
					initStream.open(fileName);
					if (!initStream.is_open())
					{
						cout << "Could not open file " << fileName << " for pregame input. Exiting..." << endl;
						return -1
					}
    			}
    			else throw string(argv[i]);
			}
			else if (argv[i] == "-deck1"s)
			{
				if (i != argc - 1)
				{
					deck1 = argv[i+1];
				}
				else throw string(argv[i]);
			}
			else if (argv[i] == "-deck2"s)
			{
				if (i != argc - 1)
				{
					deck2 = argv[i+1];
				}
				else throw string(argv[i]);
			}
			else
			{
				cout << "SUCK MY DICK" << endl;
			}
		}
		catch (string arg)
		{
			cout << "You do not use command line argument " << arg << " in this way." << endl;

		}
	}

	ifstream deckStream1, deckStream2;

	if (deck1.empty()) deckStream1.open("default.deck");
	else deckStream1.open(deck1);
	if (!deckStream1.is_open()) cout << "Error opening file: " << deck1.empty() ? "default.deck" : deck1;

	if (deck2.empty()) deckStream2.open("default.deck");
	else deckStream2.open(deck2);
	if (!deckStream2.is_open()) cout << "Error opening file: " << deck2.empty() ? "default.deck" : deck2;

	string p1Name, p2Name;
	cout << "Please enter the name of Player 1: ";
	cin >> p1Name;
	cout << "Please enter the name of Player 2: ";
	cin >> p2Name;
	Board board{p1Name, p2Name, deckStream1, deckStream2};
	TextDisplay display{&board};
	Card.initializeAbilities();

	if (initStream.is_open())
	{
		string input;
		while(getline(initStream, input))
		{
			stringstream ss{input};
			parseCommands(display, board, ss);
		}
	}

	string input;
	while (getline(cin, input))
	{
		stringstream ss{input};
		try
		{
			parseCommands(display, board, ss);
		}
		catch (string command)
		{
			cout << "That is not how you use the " << command << "command." << endl;
			showHelp();
		}
	}
	return 0;
}
