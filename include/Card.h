#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card(std::string cardName);
        virtual ~Card();
        virtual use(Face& player) =0;
        virtual use(Face& player, Unit& target)=0;
        getName(); // use for graphics
        void notifyBoard();
        int getCost();

        // Ability Implementation
        static Ability * getAbility(std::string ability);
        static void addAbility(std::string ability);
    private:
        std::string Name;
        Board* theBoard;
        //Ability Implementation
        static std::vector<Ability> listOfAbilities;

        Ability * ability;
        int cost;
};

#endif // CARD_H
