#ifndef ABILITY_H
#define ABILITY_H


class Ability
{
    public:
        Ability(std::string name);
        virtual ~Ability();

        virtual bool isTriggered() =0;

        virtual std::string getDescription()=0;

        virtual void use(Unit& target) =0;
        virtual void use(Board& theBoard) =0;

    protected:
    private:
};

#endif // ABILITY_H
