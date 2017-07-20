#ifndef ACTIVEABILITY_H
#define ACTIVEABILITY_H

#include <Ability.h>


class ActiveAbility : public Ability
{
    public:
        ActiveAbility();
        virtual ~ActiveAbility();

        bool isTriggered() override;
        void use(Unit& target) override;
        void use(Board& theBoard) override;

    protected:

    private:
};

#endif // ACTIVEABILITY_H
