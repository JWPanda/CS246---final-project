#include "TriggeredAbility.h"

TriggeredAbility::TriggeredAbility()
{
    //ctor
}

TriggeredAbility::~TriggeredAbility()
{
    //dtor
}


void use(Unit& target) override;
void use(Board& theBoard) override;
std::string FireElemental::getDescription() {
    return "Whenever an opponent's minion enteres play, deal 1 damage to it"
};

