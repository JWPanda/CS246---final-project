#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
#include "Minion.h"
#include "Spell.h"
#include "Enchantment.h"
#include "Ritual.h"

class Factory {
    public:
        //Ctor and Dtor:
        Factory();
        ~Factory(); 

        //Card Creator:
        std::shared_ptr<Card> makeCard(std::string cardname, Player* owner);
};

#endif
