#ifndef ABILITY_H
#define ABILITY_H

#include <string>

class Board;

class Ability
{
    public:
        Ability(int cost);
        virtual ~Ability();

        virtual bool isTriggered() =0;

        virtual std::string getDescription()=0;

        virtual void use(Board& theBoard, int p =-1, int t =-1) =0;
        int getCost();
    protected:
    private:
        int cost;
};

#endif // ABILITY_H

