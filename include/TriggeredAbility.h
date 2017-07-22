#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H

#include "Ability.h"


class TriggeredAbility : public Ability
{
    public:
        TriggeredAbility(int cost);
        ~TriggeredAbility();


        bool isTriggered() override;

    protected:

    private:

};

// Minion Triggered Abilities
class FireElemental_Ability : public TriggeredAbility {
    FireElemental_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

class PotionSeller_Ability : public TriggeredAbility {
    PotionSeller_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

class ManEater_Ability : public TriggeredAbility {
    ManEater_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

// Ritual Triggered Abilities

class DarkRitual_Ability : public TriggeredAbility {
    DarkRitual_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

class AuraOfPower_Ability : public TriggeredAbility {
    AuraOfPower_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

class Standstill_Ability : public TriggeredAbility {
    Standstill_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

#endif // TRIGGEREDABILITY_H

