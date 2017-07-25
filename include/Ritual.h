#ifndef RITUAL_H
#define RITUAL_H

#include "Card.h"


class Ritual : public Card
{
    public:
        //Ctor and Dtor:
        Ritual(int cost, Player* player, int charges);
        virtual ~Ritual();

        //Game Mechanics:
        void loseCharges(int i);
        void increaseCharges(int i);
        void play (Board& theBoard, int i, int p, int t) override;
        void use(Board& theBoard, std::shared_ptr<Unit> target) override;

        //Accessors:
        int getCharges() const;
        CardType getType() const override;

    private:
        int charges;
};


//Individual Rituals:
struct DarkRitual : public Ritual {
    DarkRitual(Player* player);
    std::string getName() const override;
};

struct AuraOfPower : public Ritual {
    AuraOfPower(Player* player);
    std::string getName() const override;
};

struct Standstill : public Ritual {
    Standstill(Player* player);
    std::string getName() const override;
};

#endif // RITUAL_H
