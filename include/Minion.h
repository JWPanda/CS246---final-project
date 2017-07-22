#ifndef MINION_H
#define MINION_H

#include "Unit.h"


class Minion : public Unit
{
    public:
        Minion(int cost, int Attack, int Defense, Player * player);
        virtual ~Minion();
        void die();
        void reset();

        int getType() override;

    private:
};

class AirElemental : public Minion {
    AirElemental(Player * player);
    std::string getName() override;
};

class EarthElemental : public Minion {
    EarthElemental(Player * player);
    std::string getName() override;
};

class FireElemental : public Minion {
    FireElemental(Player * player);
    std::string getName() override;
};

class PotionSeller : public Minion {
    PotionSeller(Player * player);
    std::string getName() override;
};

class NovicePyromancer : public Minion {
    NovicePyromancer(Player * player);
    std::string getName() override;
};

class ApprenticeSummoner : public Minion {
    ApprenticeSummoner(Player * player);
    std::string getName() override;
};

class MasterSummoner : public Minion {
    MasterSummoner(Player * player);
    std::string getName() override;
};

class Troll() : public Minion {
    Troll(Player * player);
    std::string getName() override;
};
#endif // MINION_H

