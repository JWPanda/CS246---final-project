#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "Factory.h"
#include "Minion.h"
#include "Face.h"
#include "Ability.h"
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
        Player( std::string Name, std::ifstream & deck, Board& theBoard);
        ~Player(); // stwill need to destroy deck/hand/etc
        static Factory myFactory;

        //Turn logistics methods:
        void draw();
        void newTurn(); // increase mana cap by 1, fill mana
        void checkTrigger(Ability::AbilityType trigger, Unit* target);

        // Game commands:
        void play(int i, int p, int t);
        void use(int i, int p, int t);
        void attack(int m1, Unit& target);

        //Move Methods:
        void moveToGraveyard(Unit* self);
        void moveToBoard(Unit* self);
        void destroyRitual();
        void moveToRitual(int i);
        void moveToDeck(Card* self);
        void placeEnchantment(Card* self);
        void revive();
        void discard(int i);

        // Accessors:
        void gainMana(int m);
        int getMana() const;
        Face* getFace(); // use for graphics and attack
        const Card* getGraveyard() const; // use for graphics, top card on graveyard
        const Card* getRitual() const; // use for graphics
        const std::vector<Card*>& getHand() const; // use for graphics
        const std::vector<Card*>& getField() const; // use for graphics

        //Helper Method:
        int findSelf(Card* self, std::vector<Card*> cvec);

    private:
        Face myFace;
        Board& theBoard;
        std::vector<Card*> myDeck;
        std::vector<Card*> myHand;
        std::vector<Card*> myField;
        std::vector<Card*> myRitual;
        std::vector<Unit*> myGraveyard;
};

#endif // PLAYER_H
