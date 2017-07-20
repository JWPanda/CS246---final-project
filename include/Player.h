#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "Board.h"
#include "Unit.h"



class Player
{
    public:
        Player(std::string Name, std::ifstream & deck);
        ~Player(); // stwill need to destroy deck/hand/etc

        // Game commands
        void draw();
        void attack(int m1);
        void attack(int m1, Unit& target);
        void use(int m1);
        void use(int m1, int m2, Board& theBoard);
        void inspect(int i);
        void newTurn(); // increase mana cap by 1, fill mana
        void checkTrigger();
        void play(int i);
        void play(int i, Unit& target);
        // Accessors
        Minion& getMinion(int i); // use when targetting minion
        std::vector<Card*> & getHand(); // use for graphics
        std::vector<Card*> & getField(); // use for graphics
        Card& getGraveyard(); // use for graphics, top card on graveyard
        Card& getRutual(); // use for graphics
        Face& getFace(); // use for graphics
        int getMana();
    private:
        int mana;
        std::vector<Card*> deck;
        std::vector<Card*> hand;
        std::vector<Card*> graveyard;
        std::vector<Card*> field;
        std::vector<Card*> ritual;
        Face player;
};

#endif // PLAYER_H
