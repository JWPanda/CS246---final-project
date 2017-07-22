#ifndef UNIT_H
#define UNIT_H

#include <Card.h>


class Unit
{
    public:
        Unit(int Attack, int Defense, Player* player);
        virtual ~Unit();
        int getAttack();
        int getDefense();
        void attack(Unit& target);
        void getHit(int attack);
        virtual die()=0;
        void isDead();

    protected:
        int Attack, Defense, BaseAttack, BaseDefense;
        Player * player;
};

#endif // UNIT_H

