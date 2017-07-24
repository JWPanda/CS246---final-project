#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>
#include <memory>
#include "Ability.h"
#include "ActiveAbility.h"
#include "TriggeredAbility.h"
#include "Ability.h"


//Predefined classes
class Board;
class Player;

class Card
{
    public:
        //Ctor & Dtor:
        Card(Player * player, int cost );
        virtual ~Card();

        //Game Mechanics:
        virtual void play (Board& theBoard, int i, int p, int t) = 0;
        virtual void use(Board& theBoard, int p, int t);
        virtual std::string getName()=0; // use for graphics
        virtual void attack(Unit& target);

        // Ability Implementation
        static void initializeAbilities();
        bool hasAbility();
        int getAbilityCost();
        void addAbility(std::string abilityName); // changes ability of the card


        //Accessors:
        int getCost();
        bool isTriggered();
        virtual int getType()=0;
        std::string getDescription();
        virtual int getAttack();
        virtual int getDefense();



        // Enchantment Implementation
        virtual std::string getEnchantmentDescription();
        virtual int getEnchantmentAttack();
        virtual int getEnchantmentDefense();
        virtual std::string getEnchantmentName();



    protected:
        std::shared_ptr<Ability> ability;
        Player * player;

    private:
        //Ability Implementation
        static std::map<std::string, std::shared_ptr<Ability>> listOfAbilities;
        int cost;
};

#endif // CARD_H
