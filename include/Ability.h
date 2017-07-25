#ifndef ABILITY_H
#define ABILITY_H
#include <string>

//predefined class:
class Board;
class Player;
class Unit;

class Ability
{
    public:
        //Ctor & Dtor:
        Ability(int cost);
        virtual ~Ability();

        //Ability Mechanics:
        virtual int isTriggered()=0;
        virtual void use(Board& theBoard, int p , int t, Player* myPlayer);
        virtual void use(Board& theBoard, int p, int t);
        int getCost();
        virtual std::string getDescription()=0;

    private:
        int cost;
};

#endif // ABILITY_H
