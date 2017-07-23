#ifndef SPELL_H
#define SPELL_H

#include <Card.h>


class Spell : public Card
{
    public:
        Spell();
        virtual ~Spell();
        use(Face& player) override;
        use(Face& player, Unit& target) override;
        CardType getType() override;

    protected:

    private:
};

#endif // SPELL_H
