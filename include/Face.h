#ifndef FACE_H
#define FACE_H

#include "Unit.h"


class Face : public Unit
{
    public:
        //Ctor & Dtor:
        Face(std::string name, Player* player);
         ~Face();

        //Mana Mechanics:
        void refillMana();
        void incMana();
        int getCurrentMana();
        void spendMana(int cost);

        // End Game:
        void die();

        // Accessors:
        int getType() override;
        std::string getName() override;

    private:
        Player* player;
        std::string name;
        int mana_cur;
        int mana_cap;

};

#endif // FACE_H
