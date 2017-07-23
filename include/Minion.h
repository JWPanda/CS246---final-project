#ifndef MINION_H
#define MINION_H

#include "Unit.h"
#include <string>


class Minion : public Unit
{
    public:
        Minion(int cost, int Attack, int Defense, Player * player);
        virtual ~Minion();

        void play(Board* theBoard, int i, int p, int t) override;

        void die();
        void reset();


        int getType() override;

    private:
};

struct AirElemental : public Minion {
    AirElemental(Player * player);
    std::string getName() override;
};

struct EarthElemental : public Minion {
    EarthElemental(Player * player);
    std::string getName() override;
};

struct FireElemental : public Minion {
    FireElemental(Player * player);
    std::string getName() override;
};

struct PotionSeller : public Minion {
    PotionSeller(Player * player);
    std::string getName() override;
};

struct NovicePyromancer : public Minion {
    NovicePyromancer(Player * player);
    std::string getName() override;
};

struct ApprenticeSummoner : public Minion {
    ApprenticeSummoner(Player * player);
    std::string getName() override;
};

struct MasterSummoner : public Minion {
    MasterSummoner(Player * player);
    std::string getName() override;
};

struct Troll : public Minion {
    Troll(Player * player);
    std::string getName() override;
};
#endif // MINION_H
