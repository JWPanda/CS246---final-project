#ifndef MINION_H
#define MINION_H

#include <Unit.h>


class Minion : public Unit
{
    public:
        Minion(std::string Name);
        virtual ~Minion();
        die(std::vector<Card*> location);
        int getAbilityCost() override;

    private:
        int BaseAttack, BaseDefense;
};

#endif // MINION_H
