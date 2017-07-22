#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include <fstream>
#include <utility>
#include <vector>

//Predefined classes:
class Board;
class Card;

class Player
{
    public:
        Player(std::string Name, std::ifstream & deck);
        ~Player(); // stwill need to destroy deck/hand/etc
        // Game commands
        void draw();
        void attack(int m1, Unit& target);
        void use(Board &theBoard, int p = -1, int t = -1);
        void newTurn(); // increase mana cap by 1, fill mana
        void checkTrigger();
        void play(int i);
        void play(int i, Unit& target);
        void die (Unit* unit);
        // Accessors
        std::vector<Card*> & getHand(); // use for graphics
        std::vector<Card*> & getField(); // use for graphics
        Card& getGraveyard(); // use for graphics, top card on graveyard
        Card& getRitual(); // use for graphics
        vector<Card *> getHand();
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
