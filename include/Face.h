#ifndef FACE_H
#define FACE_H

#include <Unit.h>


class Face : public Unit
{
    public:
        Face(std::string name, Player* player);
        virtual ~Face();
        void die();
        void refillMana();
        void incMana();
        int getCurrentMana();
        void spendMana(int cost);
    protected:

    private:
        std::string name;
        int mana_cur;
        int mana_cap;
        Player* player;
};

#endif // FACE_H
