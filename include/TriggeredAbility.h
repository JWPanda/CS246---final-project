#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H

#include <Ability.h>


class TriggeredAbility : public Ability
{
    public:
        TriggeredAbility();
        ~TriggeredAbility();


        bool isTriggered() override;
        virtual void checkTrigger(int i)=0;
        void use(Unit& target) override;
        void use(Board& theBoard) override;

    protected:

    private:

};

class FireElemental : public TriggeredAbility {
    void use(Unit& target) override;
    void use(Board& theBoard) override;
    std::string getDescription() override;
};

#endif // TRIGGEREDABILITY_H

