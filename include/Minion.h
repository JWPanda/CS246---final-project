#ifndef MINION_H
#define MINION_H

#include "Unit.h"
#include <string>


class Minion : public Unit
{
    public:
        //Ctor and Dtor:
        Minion(int cost, int Attack, int Defense, Player * player);
        virtual ~Minion();

        //Death Mechanics:
        void die();
        void reset();

        //Game Mechanics
        void play (Board& theBoard, int i, int p, int t) override;
        void unsummon() override;

        //Accessors
        CardType getType() const override;
};

// Individual Minion Classes :
struct AirElemental : public Minion {
    AirElemental(Player * player);
    std::string getName() const override;
};

struct EarthElemental : public Minion {
    EarthElemental(Player * player);
    std::string getName() const override;
};

struct FireElemental : public Minion {
    FireElemental(Player * player);
    std::string getName() const override;
};

struct PotionSeller : public Minion {
    PotionSeller(Player * player);
    std::string getName() const override;
};

struct NovicePyromancer : public Minion {
    NovicePyromancer(Player * player);
    std::string getName() const override;
};

struct ApprenticeSummoner : public Minion {
    ApprenticeSummoner(Player * player);
    std::string getName() const override;
};

struct MasterSummoner : public Minion {
    MasterSummoner(Player * player);
    std::string getName() const override;
};

struct Troll : public Minion {
    Troll(Player * player);
    std::string getName() const override;
};;
#endif // MINION_H
