#ifndef RITUAL_H
#define RITUAL_H

#include <Card.h>


class Ritual : public Card
{
    public:
        Ritual(int cost, Player* player, int charges);
        virtual ~Ritual();
        void loseCharges(int i);
        void play (Board& theBoard, int i, int p, int t) override;
        // graphic display
        int getCharges() const;
        CardType getType() const override;

    protected:

    private:
        int charges;
};

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
