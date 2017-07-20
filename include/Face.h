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

    protected:

    private:
        int mana;
};

#endif // FACE_H
