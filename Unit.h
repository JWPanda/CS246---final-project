#ifndef UNIT_H
#define UNIT_H

#include <Card.h>


class Unit : public Card
{
    public:
        Unit(std::string Name);
        Unit(int cost,int Attack, int Defense);
        virtual ~Unit();
        int getAttack();
        int getDefense();
        void attack(Unit& target);
        void getHit(int attack);
        virtual die(std::vector<Card*> location)=0;

        use(Face& player);
        use(Face& player, Unit& target);

    protected:
        int Attack, Defense;
};

#endif // UNIT_H
