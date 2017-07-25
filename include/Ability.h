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
      enum AbilityType {NONE, ACTIVE, BEGIN, END, ENTER, DEATH};

        //Ctor & Dtor:
        Ability(int cost);
        virtual ~Ability();

        //Ability Mechanics:
        virtual AbilityType checkAbility()= 0;
        virtual void use(Board& theBoard, int p , int t, Player* myPlayer);
        virtual void use(Board& theBoard, Unit& target, Player* enemy, Player* friendly);
        int getCost();
        virtual std::string getDescription()=0;

    private:
        int cost;
};

#endif // ABILITY_H
