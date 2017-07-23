#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "Minion.h"
#include "Face.h"
#include <fstream>
#include <utility>
#include <vector>

//Predefined classes:
class Board;
class Card;

class Player
{
    public:
        // Ctor & Dtor:
        Player( std::string Name, std::ifstream & deck);
        ~Player(); // stwill need to destroy deck/hand/etc

        //Turn logistics methods:
        void draw();
        void newTurn(); // increase mana cap by 1, fill mana
      //void checkTrigger();

        // Game commands:
        void play(int i);
        //void play(Board &theBoard, int i, int p, int t);
        //void use(Board &theBoard,int i, int p = -1, int t = -1);
        //void attack(int m1, Unit& target);

        // Accessors:
        int getMana();
        Face& getFace(); // use for graphics
        //Card& getRitual(); // use for graphics
        //Card& getGraveyard(); // use for graphics, top card on graveyard
        std::vector<Card*> & getHand(); // use for graphics
        std::vector<Card*> & getField(); // use for graphics

    private:
        Face myFace;
        std::vector<Card*> myDeck;
        std::vector<Card*> myHand;
        std::vector<Card*> myField;
        //std::vector<Card*> myRitual;
        //std::vector<Card*> myGraveyard;
};

#endif // PLAYER_H
