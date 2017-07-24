#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "Factory.h"
#include "Minion.h"
#include "Face.h"
#include <fstream>
#include <memory>
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
        static Factory myFactory;

        //Turn logistics methods:
        void draw();
        void newTurn(); // increase mana cap by 1, fill mana
      //void checkTrigger();

        // Game commands:
        void play(Board &theBoard, int i, int p, int t);
        //void use(Board &theBoard,int i, int p = -1, int t = -1);
        //void attack(int m1, Unit& target);

        //Move Functions:
        void moveToGraveyard(int i);
        void moveToBoard(int i);
        void moveToRitual(int i);
        void discard(int i);

        // Accessors:
        int getMana() const;
        const Face* getFace() const; // use for graphics
        const Card* getGraveyard() const; // use for graphics, top card on graveyard
        const Card* getRitual() const; // use for graphics
        const std::vector<Card*>& getHand() const; // use for graphics
        const std::vector<Card*>& getField() const; // use for graphics

    private:
        Face myFace;
        std::vector<Card*> myDeck;
        std::vector<Card*> myHand;
        std::vector<Card*> myField;
        std::vector<Card*> myRitual;
        std::vector<Card*> myGraveyard;
};

#endif // PLAYER_H
