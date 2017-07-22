#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card(int cost);
        virtual ~Card();
        void use(Board& theBoard, int p =0, int t = 0);
        virtual std::string getName()=0; // use for graphics
        void notifyBoard();
        int getCost();

        // Ability Implementation
        static void initialize_Abilities();
        void addAbility(std::string abilityName); // changes ability of the card
        bool hasAbility();
        int getAbilityCost();
        bool isTriggered();
        std::string getDescription();

        virtual int getAttack()=0;
        virtual int getDefense()=0;

    protected:
        std::shared_ptr<Ability *> ability;
    private:
        Board* theBoard;
        //Ability Implementation
        static std::map<std::string,shared_ptr<Ability>> listOfAbilities;

        int cost;
};

#endif // CARD_H
