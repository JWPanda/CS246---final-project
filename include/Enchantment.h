#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <Unit.h>


class Enchantment : public Unit
{
    public:
        Enchantment();
        virtual ~Enchantment();
        void Enchant(Unit& target); // set Unit pointer
        int getCost();

    protected:
        Unit& base;
    private:
};

#endif // ENCHANTMENT_H
