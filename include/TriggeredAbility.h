#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H

#include <Ability.h>


class TriggeredAbility : public Ability
{
    public:
        TriggeredAbility(int cost);
        ~TriggeredAbility();


        bool isTriggered() override;

    protected:

    private:

};

class FireElemental_Ability : public TriggeredAbility {
    void use(Board& theBoard, int p = 0, int t =0) override;
    std::string getDescription() override;
};

class PotionSeller_Ability : public TriggeredAbility {
    void use(Board& theBoard, int p = 0, int t =0) override;
    std::string getDescription() override;
};

class ManEater_Ability : public TriggeredAbility {
    void use(Board& theBoard, int p = 0, int t =0) override;
    std::string getDescription() override;
};

#endif // TRIGGEREDABILITY_H

