#ifndef BOARD_H
#define BOARD_H
#include <fstream>
#include "Player.h"
#include "Ability.h"

class Card;
class Board
{
    public:
        //Ctor & Dtor::
        Board (std::string name1, std::string name2, std::ifstream &deck1, std::ifstream &deck2, bool testing);
        ~Board();

        //Game Mechanics
        void changeTurn();
        void checkTrigger(Ability::AbilityType trigger, std::shared_ptr<Unit> target = nullptr);

        //Game Commands:
        void play(int i, int p = -1, char t = 'e');
        void use(int i, int p = -1, int t = -1);
        void attack(int m1, int m2 = -1);

        // Accessors:
        std::shared_ptr<Unit> getMinion (int i, int player = 0) const;
        Player* getActivePlayer() const;
        Player * getNonActivePlayer() const;
        Player* getPlayer(int i);

    private:
        Player p1;
        Player p2;
        Player* activePlayer;
        Player* nonActivePlayer;
};

#endif // BOARD_H
