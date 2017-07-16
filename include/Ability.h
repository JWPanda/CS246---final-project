#ifndef ABILITY_H
#define ABILITY_H


class Ability
{
    public:
        Ability();
        virtual ~Ability();

        virtual bool isTriggered() =0;

        std::string getName();
        std::string getDescription();

        virtual void use(Unit& target) =0;
        virtual void use(Board& theBoard) =0;

    protected:
        std::string name;
    private:
        std::string description;
};

#endif // ABILITY_H
