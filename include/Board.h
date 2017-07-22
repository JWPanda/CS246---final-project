#ifndef BOARD_H
#define BOARD_H
#include <fstream>
#include "Player.h"

class Card;
class Board
{
    public:
        Board (std::string name1, std::string name2, std::ifstream &deck1, std::ifstream &deck2);
        ~Board();
        void changeTurn();
        void play(int i);
        void play(int i, int p, int t);
        void use(int i);
        void use(int i, int p, int t);
        void attack(int m1, int m2 = -1);
        Card &getMinion (int i, int player = 0); 
        void drawBoard();  // Iggy figure this out include other shit if needed
        //void inspect(int m1);
        void checkTrigger(int trigger);
        Player* getActivePlayer();
    
    friend class TextDisplay;

    private:
        Player* activePlayer;
        Player* nonActivePlayer;
    protected: 
        Player p1;
        Player p2;
};

#endif // BOARD_H
