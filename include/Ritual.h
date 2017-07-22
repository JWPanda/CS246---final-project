#ifndef RITUAL_H
#define RITUAL_H

#include <Card.h>


class Ritual : public Card
{
    public:
        Ritual();
        virtual ~Ritual();

        use(Face& player) override;
        use(Face& player, Unit& target) override;


        // graphic display
        int getCharges();

    protected:

    private:
        int charges;
};

#endif // RITUAL_H
