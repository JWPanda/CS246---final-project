#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H

#include <Ability.h>


class TriggeredAbility : public Ability
{
    public:
        TriggeredAbility();
        ~TriggeredAbility();


        bool isTriggered() override;
        void checkTrigger(int i);
        void use(Unit& target) override;
        void use(Board& theBoard) override;

    protected:

    private:

};

#endif // TRIGGEREDABILITY_H
