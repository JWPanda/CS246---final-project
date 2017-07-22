#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "Face.h"
#include "Minion.h"
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
        void use(Board &theBoard, int i,  int p, int t);
        void newTurn(); // increase mana cap by 1, fill mana
        //void checkTrigger(int trigger);
        void play(int i);
        void play(int i, Unit& target);
        void die (Unit* unit);
        // Accessors
        std::vector<Card*> & getHand(); // use for graphics
        std::vector<Card*> & getField(); // use for graphics
        Card* getGraveyard(); // use for graphics, top card on graveyard
        Card* getRitual(); // use for graphics
        Face* getFace();// use for graphics
        Unit &getTarget(int i);
        int getMana();
    private:
        int mana;
        std::vector<Card*> myDeck;
        std::vector<Card*> myHand;
        std::vector<Card*> myGraveyard;
        std::vector<Card*> myField;
        std::vector<Card*> myRitual;
        Face myFace;
};

#endif // PLAYER_H
