#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card(std::string cardName);
        virtual ~Card();
        virtual use(Face& player) =0;
        virtual use(Face& player, Unit& target)=0;
        virtual std::string getName(); // use for graphics
        void notifyBoard();
        int getCost();

        // Ability Implementation
        static Ability * getAbility(std::string ability);
        static void addAbility(std::string ability);
    protected:
        Ability * ability;
    private:
        std::string Name;
        Board* theBoard;
        //Ability Implementation
        static std::vector<Ability> listOfAbilities;


        int cost;
};

#endif // CARD_H
