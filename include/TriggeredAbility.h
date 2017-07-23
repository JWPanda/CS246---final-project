#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H
#include <string>
#include "Ability.h"


class TriggeredAbility : public Ability
{
    public:
        TriggeredAbility(int cost);
        ~TriggeredAbility();


        int isTriggered() override;

    protected:

    private:

};

// Minion Triggered Abilities
struct FireElemental_Ability : public TriggeredAbility {
    FireElemental_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

struct PotionSeller_Ability : public TriggeredAbility {
    PotionSeller_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

struct Troll_Ability : public TriggeredAbility {
    Troll_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

// Ritual Triggered Abilities

struct DarkRitual_Ability : public TriggeredAbility {
    DarkRitual_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

struct AuraOfPower_Ability : public TriggeredAbility {
    AuraOfPower_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

struct Standstill_Ability : public TriggeredAbility {
    Standstill_Ability();
    void use(Board& theBoard, int p, int t) override;
    std::string getDescription() override;
};

#endif // TRIGGEREDABILITY_H
