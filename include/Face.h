#ifndef FACE_H
#define FACE_H

#include <Unit.h>


class Face : public Unit
{
    public:
        Face();
        virtual ~Face();
        die(std::vector <Card*> location);
        void refillMana();
        void incMana();

        int getAbilityCost() override;
        use(Face& player) override;
        use(Face& player, Unit& target) override;

    protected:

    private:
        int mana_cur;
        int mana_cap;
};

#endif // FACE_H
