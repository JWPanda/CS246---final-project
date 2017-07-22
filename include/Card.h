#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>
#include <memory>
#include "ActiveAbility.h"
#include "TriggeredAbility.h"
#include "Ability.h"

class Board;
class Player;

class Card
{
    public:
        Card(int cost, Player * player);
        virtual ~Card();
        void use(Board& theBoard, int p =0, int t = 0);
        virtual std::string getName()=0; // use for graphics
        //void notifyBoard();
        int getCost();

        // Ability Implementation
        static void initialize_Abilities();
        void addAbility(std::string abilityName); // changes ability of the card
        virtual bool hasAbility();
        virtual int getAbilityCost();
        bool isTriggered();
        virtual std::string getDescription();

        // Enchantment Implementation
        virtual std::string getEnchantmentDescription();
        virtual int getEnchantmentAttack();
        virtual int getEnchantmentDefense();

        virtual void attack(Unit& target);
        virtual int getAttack()=0;
        virtual int getDefense()=0;
        virtual int getType()=0;

    protected:
        std::shared_ptr<Ability *> ability;
        Player * player;
    private:
        Board* theBoard;
        //Ability Implementation
        static std::map<std::string,std::shared_ptr<Ability*>> listOfAbilities;

        int cost;
};

#endif // CARD_H
