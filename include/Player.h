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
<<<<<<< HEAD
        Face* getFace(); // use for graphics
=======
        Face& getFace(); // use for graphics
>>>>>>> fafbc69446a67c8bceba59c123c6d0175976c241
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
