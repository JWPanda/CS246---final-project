#ifndef UNIT_H
#define UNIT_H

#include <Card.h>


class Unit : public Card
{
    public:
        Unit(int cost,int Attack, int Defense, Player* player);
        virtual ~Unit();

        int getAttack() override;
        int getDefense() override;

        void attack(Unit& target);
        void getHit(int attack);
        virtual void die()=0;
        void isDead();

    protected:
        int Attack, Defense, BaseAttack, BaseDefense;
};

#endif // UNIT_H

