#ifndef MINION_H
#define MINION_H

#include <Unit.h>


class Minion : public Unit
{
    public:
        Minion(int BaseAttack, int BaseDefense);
        virtual ~Minion();
        die(std::vector<Card*> location);

    private:
        int BaseAttack, BaseDefense;
};

class AirElemental : public Minion {
    AirElemental();
};

class EarthElemental : public Minion {
    EarthElemental();
};

class FireElemental : public Minion {
    FireElemental();
};

class PotionSeller : public Minion {
    PotionSeller();
};

class NovicePyromancer : public Minion {
    NovicePyromancer();
};

class ApprenticeSummoner : public Minion {
    ApprenticeSummoner();
};

class MasterSummoner : public Minion {
    MasterSummoner();
};


#endif // MINION_H

