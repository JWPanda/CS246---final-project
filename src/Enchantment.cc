#include "Enchantment.h"

Enchantment(std::string name);
        virtual ~Enchantment();
        void Enchant(Unit& target); // set Unit pointer
        int getCost();
