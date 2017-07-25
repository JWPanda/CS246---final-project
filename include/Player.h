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
        Player(std::string Name, std::ifstream & deck, int playerNum, Board& theBoard, bool testing);
        ~Player(); // stwill need to destroy deck/hand/etc
        static Factory myFactory;

        //Turn logistics methods:
        void draw();
        void newTurn(); // increase mana cap by 1, fill mana
        void shuffleDeck(); // Shuffles your deck
        void checkTrigger(Ability::AbilityType trigger, std::shared_ptr<Unit> target);

        // Game commands:
        void play(int i, int p, int t);
        void use(int i, int p, int t);
        void attack(int m1, std::shared_ptr<Unit> target);

        //Move Methods:
        void moveToGraveyard(std::shared_ptr<Unit> self);
        void moveToBoard(std::shared_ptr<Unit> self);
        void destroyRitual();
        void moveToRitual(int i);
        void moveToDeck(std::shared_ptr<Card> self);
        void placeEnchantment(std::shared_ptr<Card> self);
        void revive();
        void discard(int i);

        // Accessors:
        int getMana() const;
        int getNumber() const;
        std::shared_ptr<Face> getFace(); // use for graphics and attack
        const std::shared_ptr<Card> getGraveyard() const; // use for graphics, top card on graveyard
        const std::shared_ptr<Card> getRitual() const; // use for graphics
        const std::vector<std::shared_ptr<Card>>& getHand() const; // use for graphics
        const std::vector<std::shared_ptr<Card>>& getField() const; // use for graphics

        //Helper Method:
        int findSelf(std::shared_ptr<Card> self, const std::vector<std::shared_ptr<Card>> &cvec);

    private:
        int number;
        std::shared_ptr<Face> myFace;
        Board& theBoard;
        std::vector<std::shared_ptr<Card>> myDeck;
        std::vector<std::shared_ptr<Card>> myHand;
        std::vector<std::shared_ptr<Card>> myField;
        std::vector<std::shared_ptr<Card>> myRitual;
        std::vector<std::shared_ptr<Unit>> myGraveyard;
};

#endif // PLAYER_H
