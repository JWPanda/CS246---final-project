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

        //Death Mechanics:
        void reduceAttack(int i);
        virtual void die()=0;
        void isDead();

        //Accessors:
        int getAttack() const override;
        int getDefense() const override;

    protected:
        int Attack, Defense, BaseAttack, BaseDefense;
};

#endif // UNIT_H
