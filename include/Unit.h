#ifndef UNIT_H
#define UNIT_H

#include "Card.h"


class Unit : public Card
{
    public:
        //Ctor & Dtor:
        Unit(int cost,int Attack, int Defense, Player* player);
        virtual ~Unit();

        //Attack Mechanics:
        void attack(Unit& target);
        void getHit(int attack);
        void gainStats(int atk, int def);

        //Death Mechanics:
        virtual void die() = 0;
        void isDead();
        virtual void disenchant();
        //Accessors:
        bool OnBoard() const;
        int getAttack() const override;
        int getDefense() const override;


    protected:
        int Attack, Defense, BaseAttack, BaseDefense;
        bool Action, onBoard;
};

#endif // UNIT_H
