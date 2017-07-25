#ifndef SPELL_H
#define SPELL_H

#include "Card.h"

class Board;
class

class Spell : public Card
{
    public:
        Spell(int cost, Player* player);
        virtual ~Spell();
        void play(Board& theBoard, int i, int p, int t) override;
        Card::CardType getType() override;
    protected:

    private:
};



// Spell cards
struct Banish : public Spell {
    Banish(Player* player);
    std::string getName() override;
};

struct Unsummon : public Spell {
    Unsummon(Player* player);
    std::string getName() override;
};

struct Recharge : public Spell {
    Recharge(Player* player);
    std::string getName() override;
};

struct Disenchant : public Spell {
    Disenchant(Player* player);
    std::string getName() override;
};

struct RaiseDead : public Spell {
    RaiseDead(Player* player);
    std::string getName() override;
};

struct Blizzard : public Spell {
    Blizzard(Player* player);
    std::string getName() override;
};

#endif // SPELL_H
