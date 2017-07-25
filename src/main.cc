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
									"\n\t\t-lit -- You're in for a treat" << endl;
}

bool parseCommand(TextDisplay display, Board &board, string input, bool testing)
{
  stringstream ss{input};
	string command;
	ss >> command;
	if (command == "help")
	{
		// Help command
		showMainHelp();
	}
	else if (command == "end")
	{
		// Switch player turn
		board.changeTurn();
	}
	else if (command == "quit")
	{
		return true;
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
			try
			{
				p->draw();
				display.displayHand();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
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
			int i;
			cin >> i;
			Player* p = board.getActivePlayer();
			try
			{
				p->discard(i-1);
				display.displayHand();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
		}
	}
	else if (command == "attack")
	{
		// Attack a minion
		int i;
		ss >> i;
		if (ss.fail()) throw command;
		int j;
		ss >> j;
		if (ss.fail())
		{
			try
			{
				board.attack(i-1);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
				return 0;
			}
			catch (const int w)
			{
				cout << "Player " + to_string(w) + "has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
		}
		else
		{
			try
			{
				board.attack(i-1, j-1);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
				return 0;
			}
			catch (const int w)
			{
				cout << "Player " + to_string(w) + "has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
		}
	}
	else if (command == "play")
	{
		// Play card
		int i;
		ss >> i;
		if (ss.fail()) throw command;
		int p;
		char t;
		ss >> p;
		if (ss.fail())
		{
			try
			{
				board.play(i-1);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
			catch (const int w)
			{
				cout << "Player " + to_string(w) + "has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
		}
		else
		{
			ss >> t;
			if (ss.fail()) throw command;
			try
			{
				board.play(i-1, p, t);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
			catch (const int w)
			{
				cout << "Player " + to_string(w) + "has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
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
			try
			{
				board.use(i-1);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
			catch (const int w)
			{
				cout << "Player " + to_string(w) + "has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
		}
		else
		{
			ss >> t;
			if (ss.fail()) throw command;
			try
			{
				board.use(i-1, p, t-1);
				display.displayBoard();
			}
			catch (const string e)
			{
				cout << e << endl;
			}
			catch (const int w)
			{
				cout << board.getPlayer(w)->getFace()->getName() + " has won!!" << endl;
				cout << "Game Over." << endl;
				return true;
			}
		}
	}
	else if (command == "inspect")
	{
		// Inspect minion
		int i;
		ss >> i;
		if (ss.fail()) throw command;
		display.displayCard(i-1);
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
		cout << "Error: Invalid Command" << endl;
		showMainHelp();
	}
    return false;
}

int main(int argc, char* argv[])
{
	bool testing = false, lit = false;
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
						return -1;
					}
    			}
    			else throw string(argv[i]);
    			++i;
			}
			else if (argv[i] == "-deck1"s)
			{
				if (i != argc - 1)
				{
					deck1 = argv[i+1];
				}
				else throw string(argv[i]);
				++i;
			}
			else if (argv[i] == "-deck2"s)
			{
				if (i != argc - 1)
				{
					deck2 = argv[i+1];
				}
				else throw string(argv[i]);
				++i;
			}
			else if (argv[i] == "-lit"s)
			{
				lit = true;
			}
			else
			{
				cout << "Error: invalid command" << endl;
				showCommandLineHelp();
			}
		}
		catch (string arg)
		{
			cout << "You do not use command line argument " << arg << " in this way." << endl;
			showCommandLineHelp();
		}
	}

	ifstream deckStream1, deckStream2;

	if (deck1.empty()) deckStream1.open("deck1.txt");
	else deckStream1.open(deck1);
	if (!deckStream1.is_open()) cout << "Error opening file: " << deck1.empty() ? "default.deck" : deck1;

	if (deck2.empty()) deckStream2.open("deck2.txt");
	else deckStream2.open(deck2);
	if (!deckStream2.is_open()) cout << "Error opening file: " << deck2.empty() ? "default.deck" : deck2;

	string p1Name, p2Name;
	cout << "Please enter the name of Player 1: ";
	getline(cin, p1Name);
	cout << "Please enter the name of Player 2: ";
	getline(cin, p2Name);
	Card::initializeAbilities();
	try
	{
		Board board{p1Name, p2Name, deckStream1, deckStream2};
		TextDisplay display{&board, lit};
		if (initStream.is_open())
		{
			string input;
			while(getline(initStream, input))
			{
				istringstream ss{input};
				if (parseCommand(display, board, input, testing)) return 0;
			}
		}
		string input;
		while (getline(cin, input))
		{
			try
			{
				if (parseCommand(display, board, input, testing)) return 0;
			}
			catch (string command)
			{
				cout << "That is not how you use the " << command << " command." << endl;
				showMainHelp();
			}
		}
	}
	catch (const string e)
	{
		cout << e << endl;
		return -1;
	}
	return 0;
}
