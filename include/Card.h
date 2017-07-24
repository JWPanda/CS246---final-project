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
        enum CardType { MINION, SPELL, RITUAL, ENCHANTMENT, FACE };
        //Ctor & Dtor:
        Card(Player * player, int cost );
        virtual ~Card();

        virtual void play (Board& theBoard, int i, int p, int t)=0;

        //void use(Board& theBoard, int p =0, int t = 0);
        virtual std::string getName() const =0; // use for graphics

        // Ability Implementation
        static void initializeAbilities();

        virtual bool hasAbility() const;
        virtual int getAbilityCost() const;
        virtual int getCharges() const;
        void addAbility(std::string abilityName); // changes ability of the card

        //Accessors:
        int getCost() const;
        int isTriggered() const;
        virtual CardType getType() const = 0;
        virtual std::string getDescription() const;
        virtual int getAttack() const;
        virtual int getDefense() const;


        // Enchantment Implementation
        virtual std::string getEnchantmentName() const;
        virtual std::string getEnchantmentDescription() const;
        virtual int getEnchantmentAttack() const;
        virtual int getEnchantmentDefense() const;

    protected:
        std::shared_ptr<Ability> ability;
        Player * player;

    private:
        //Ability Implementation
        static std::map<std::string, std::shared_ptr<Ability>> listOfAbilities;
        int cost;
};

#endif // CARD_H
