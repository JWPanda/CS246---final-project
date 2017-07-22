#ifndef ACTIVEABILITY_H
#define ACTIVEABILITY_H

#include <Ability.h>


class ActiveAbility : public Ability
{
    public:
        ActiveAbility(int cost);
        virtual ~ActiveAbility();

        bool isTriggered() override;


    protected:

    private:
};

class NovicePyromancer_Ability : public ActiveAbility {
    NovicePyromancer_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

class ApprenticeSummoner_Ability : public ActiveAbility {
    ApprenticeSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

class MasterSummoner_Ability : public ActiveAbility {
    MasterSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

#endif // ACTIVEABILITY_H
