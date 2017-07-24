#ifndef BOARD_H
#define BOARD_H
#include <fstream>
#include "Player.h"

class Card;
class Board
{
    public:
        //Ctor & Dtor::
        Board (std::string name1, std::string name2, std::ifstream &deck1, std::ifstream &deck2);
        ~Board();

        //Game Mechanics
        void changeTurn();
        //void checkTrigger(int trigger);

        //Game Commands:
        void play(int i, int p = -1, char t = 'e');
        //void use(int i, int p = -1, int t = -1);
        void attack(int m1, int m2 = -1);

        // Accessors:
        Unit &getMinion (int i, int player = 0) const;
        Player* getActivePlayer() const;
        const Player* getPlayer(int i) const;

    friend class TextDisplay;

    private:
        Player p1;
        Player p2;
        Player* activePlayer;
        Player* nonActivePlayer;
};

#endif // BOARD_H
