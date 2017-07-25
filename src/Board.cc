#include "Board.h"
#include <iostream>
#include <string>

using namespace std;


// Ctor and Dtor----------------------------------------------------------------
Board::Board(string name1, string name2, ifstream &deck1, ifstream &deck2) : p1{name1, deck1, *this}, p2{name2, deck2, *this}, activePlayer{&p1}, nonActivePlayer{&p2} {}

Board::~Board() {}


//Game Mechanics----------------------------------------------------------------
void Board::changeTurn () {
    // checks end turn trigger for active player which only occurs if it is not the first turn.
    checkTrigger(Ability::BEGIN);
    swap(activePlayer, nonActivePlayer);
    activePlayer->newTurn(); // initiates new turn for active player
    checkTrigger(Ability::END);
}

void Board::checkTrigger(Ability::AbilityType trigger, Unit* target) {
    // NONE = no ability
    // BEGIN = beginning of turn
    // END = end of turn
    // ENTER = minion is played
    // DEATH = minion dies
    if (trigger == Ability::BEGIN || trigger == Ability::END) {
        activePlayer->checkTrigger(trigger, target);
    }
    else {
        activePlayer->checkTrigger(trigger, target);
        nonActivePlayer->checkTrigger(trigger, target);
    }
}


//Game Commands----------------------------------------------------------------
void Board::play (int i, int p, char t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field
    if (t == 'r') activePlayer->play(i , p , 6);
    else {
      int index = t - '0';
      activePlayer->play (i , p , index-1);
    }
}


void Board::use (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field
    activePlayer->use( i, p, t);
}


void Board::attack (int m1, int m2) {
    if (m2 != -1) { //  attack an enemy minon
        Unit& target =  getMinion (m2, 0);
        activePlayer->attack(m1, target);
    } else { // attack the enemy face
        Unit& target = dynamic_cast<Unit&>(*(nonActivePlayer->getFace()));
        activePlayer->attack(m1, target);
    }
}


// Accessors--------------------------------------------------------------------
Unit& Board::getMinion (int i, int player) const {
    if (player == 1) {
        int field_size = p1.getField().size();
        if (i >= field_size) throw "Error: there is no minion at "s + to_string(i+1) + " on your field";
        Unit& target = dynamic_cast<Unit&>(*(p1.getField()[i]));
        return target;
    }
    else if (player == 2) {
        int field_size = p2.getField().size();
        if (i >= field_size) throw "Error: there is no minion at "s + to_string(i+1) + " on your field";
        Unit& target = dynamic_cast<Unit&>(*(p2.getField()[i]));
        return target;
    }
    else {
        int field_size = nonActivePlayer->getField().size();
        if (i >= field_size) throw "Error: there is no minion at "s + to_string(i+1) + " on your field";
        Unit& target = dynamic_cast<Unit&>(*(nonActivePlayer->getField()[i]));
        return target;
    }
}

Player* Board::getActivePlayer() const {
  return activePlayer;
}

Player* Board::getPlayer(int i) {
  if (i == 1) return &p1;
  else return &p2;
}
