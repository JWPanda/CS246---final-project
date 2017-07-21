#include "Card.h"

Card::Card(Ability *ability, string Name, Board *theBoard, vector<Ability> listOfAbilities, int cost, int type): ability{nullptr} Name{Name}, theBoard{theBoard}, cost{cost}, type{type} {}

Card::~Card() {}

void notifyBoard();

int getCost() {
    return cost;
}

int getType() {
    return type;
}

int getAbilityCost () {
    if (this->ability == nullptr) return 0;
    else return this->ability.getAbilityCost();
}
