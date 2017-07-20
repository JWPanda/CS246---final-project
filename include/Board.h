#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Card.h"
#include "Unit.h"
#include "Player.h"



class Board
{
    public:
        Board(Player*p1, Player*p2, Player*activePlayer, Player*nonActivePlayer);
        ~Board()
        void changeTurn();
        void play(int i);
        void play(int i, int p, int t);
        void use(int i);
        void use (int i, int j);
        void attack(int m1, int m2 = -1);
        void drawBoard();  // Iggy figure this out include other shit if needed
        void inspect(int m1);
        void checkTrigger(int trigger);

    private:
        Player* p1;
        Player* p2;
        Player* activePlayer;
        Player* nonActivePlayer;

};

#endif // BOARD_H
