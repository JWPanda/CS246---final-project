#ifndef UNIT_H
#define UNIT_H

#include <Card.h>


class Unit : public Card
{
    public:
        Unit(std::string Name);
        virtual ~Unit();
        int getAttack();
        int getDefense();
        void attack(Unit& target);
        void getHit(int attack);
        virtual die(std::vector<Card*> location);

        virtual int getAbilityCost();
        use(Face& player);
        use(Face& player, Unit& target);

    protected:
        int Attack, Defense;
};

#endif // UNIT_H
