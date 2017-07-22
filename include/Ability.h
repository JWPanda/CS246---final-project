#ifndef ABILITY_H
#define ABILITY_H


class Ability
{
    public:
        Ability(int cost);
        virtual ~Ability();

        virtual bool isTriggered() =0;

        virtual std::string getDescription()=0;

        virtual void use(Board& theBoard, int p, int t) =0;
        int getCost();
    protected:
    private:
        int cost
};

#endif // ABILITY_H

