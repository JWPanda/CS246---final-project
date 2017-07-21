#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card(std::string cardName);
        virtual ~Card();
        void use(Board& theBoard, int p =0, int t = 0);
        virtual std::string getName(); // use for graphics
        void notifyBoard();
        int getCost();

        // Ability Implementation
        static void initialize_Abilities();
        void addAbility(std::string abilityName); // changes ability of the card
    protected:
        std::shared_ptr<Ability *> ability;
    private:
        std::string Name;
        Board* theBoard;
        //Ability Implementation
        static std::map<std::string,shared_ptr<Ability>> listOfAbilities;


        int cost;
};

#endif // CARD_H
