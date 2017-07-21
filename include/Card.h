#ifndef CARD_H
#define CARD_H
#include <utility>
#include <vector>
#include "Face.h"
#include "Unit.h"
#include "Player.h"
#include "Board.h"

class Card
{
    public:
        Card(std::string cardName);
        virtual ~Card();
        virtual use(Face& player) =0;
        virtual use(Face& player, Unit& target)=0;
        virtual std::string getName(); // use for graphics
        void notifyBoard();
        int getCost();
        int getType();

        // Ability Implementation
        static Ability * getAbility(std::string ability);
        int getAbilityCost (Ability *ability);
        static void addAbility(std::string ability);
    protected:
        Ability * ability;
    private:
        std::string Name;
        Board* theBoard;
        //Ability Implementation
        static std::vector<Ability> listOfAbilities;
        int cost;
        int type;
            // 1 = minon
            // 2 = spell
            // 3 = ritual
            // 4 = enchantment
    };

#endif // CARD_H
