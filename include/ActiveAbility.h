#ifndef ACTIVEABILITY_H
#define ACTIVEABILITY_H

#include <Ability.h>


class ActiveAbility : public Ability
{
    public:
        ActiveAbility(int cost);
        virtual ~ActiveAbility();

        bool isTriggered() override;
        int getCost();

    protected:

    private:
        int cost;
};

class NovicePyromancer_Ability : public ActiveAbility {
    NovicePyromancer_Ability(int cost);
    void use(Unit& target) override;
    void use(Board& theBoard) override;
    std::string getDescription() override;
};

class ApprenticeSummoner_Ability : public ActiveAbility {
    ApprenticeSummoner_Ability(int cost);
    void use(Unit& target) override;
    void use(Board& theBoard) override;
    std::string getDescription() override;
};

class MasterSummoner_Ability : public ActiveAbility {
    MasterSummoner_Ability(int cost);
    void use(Unit& target) override;
    void use(Board& theBoard) override;
    std::string getDescription() override;
};

#endif // ACTIVEABILITY_H
