#ifndef FACE_H
#define FACE_H
#include <Unit.h>


class Face : public Unit
{
    public:
        Face();
        virtual ~Face();
        int getAbilityCost() override;
        use(Face& player) override;
        use(Face& player, Unit& target) override;

    protected:

    private:
    //mana is handled in the player so i removed the private fields
};

#endif // FACE_H
