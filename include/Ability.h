#ifndef ABILITY_H
#define ABILITY_H
#include <string>

//predefined class:
class Board;

class Ability
{
    public:
        //Ctor & Dtor:
        Ability(int cost);
        virtual ~Ability();

        //Ability Mechanics:
        virtual bool isTriggered()=0;
        virtual void use(Board& theBoard, int p =-1, int t =-1)=0;

        //Accessors:
        int getCost();
        virtual std::string getDescription()=0;

    private:
        int cost;
};

#endif // ABILITY_H
