#ifndef FACE_H
#define FACE_H

#include "Unit.h"


class Face : public Unit
{
    public:
        //Ctor & Dtor:
        Face(std::string name, Player* player);
         ~Face();

        //stuff:
         void play (Board &theBoard, int i, int p, int t ) override;

        //Mana Mechanics:
        void refillMana();
        void incMana();
        void getMana(int m);
        void gainMana(int m);
        int getCurrentMana() const;
        void spendMana(int cost);

        // End Game:
        void die();

        // Accessors:
        CardType getType() const override;
        std::string getName() const override;

    private:
        std::string name;
        int mana_cur;
        int mana_cap;

};

#endif // FACE_H
