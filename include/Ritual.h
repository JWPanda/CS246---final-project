#ifndef RITUAL_H
#define RITUAL_H

#include <Card.h>


class Ritual : public Card
{
    public:
        Ritual(int cost, Player* player, int charges);
        virtual ~Ritual();
        void loseCharges(int i);

        // graphic display
        int getCharges();

    protected:

    private:
        int     charges;
};

class DarkRitual : public Ritual {
    DarkRitual();
    std::string getName() override;
};

class AuraOfPower : public Ritual {
    AuraOfPower();
    std::string getName() override;
};

class Standstill : public Ritual {
    Standstill();
    std::string getName() override;
};

#endif // RITUAL_H
