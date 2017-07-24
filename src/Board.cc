#include "Board.h"
using namespace std;


// Ctor and Dtor----------------------------------------------------------------
Board::Board(string name1, string name2, ifstream &deck1, ifstream &deck2) : p1{name1,deck1}, p2{name2, deck2}, activePlayer{&p1}, nonActivePlayer{&p2} {}

Board::~Board() {}


//Game Mechanics----------------------------------------------------------------
void Board::changeTurn () {
    // checks end turn trigger for active player which only occurs if it is not the first turn.
    //if (activePlayer != nullptr) //TODO checkTrigger(2);
    swap(activePlayer, nonActivePlayer);
    activePlayer->newTurn(); // initiates new turn for active player
   //TODO checkTrigger(1);  check new turn trigddger for active player
}

/*void Board::checkTrigger(int trigger) {
    // 1 = beginning of turn
    // 2 = end of turn
    // 3 = minion is played
    // 4 = minion dies
    if (trigger == 1 || trigger == 2) {
        activePlayer.checkTrigger(this, trigger)
    }
    else {
        activePlayer.checkTrigger(trigger);
        nonActivePlayer.checkTrigger(trigger);
    }
}
*/

//Game Commands----------------------------------------------------------------
void Board::play (int i, int p, char t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field
    if (t == 'r') activePlayer->play(*this, i , p , 6);
    else {
      int index = t - '0';
      activePlayer->play(*this, i , p , index-1);
    }
}

/*
void Board::use (int i) {
    activePlayer.use(this, i);
}

void Board::use (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field

    activePlayer.use(this, i, p, t)
}
*/

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
Unit& Board::getMinion (int i , int player) const {
    if (player == 1) {
      Unit& target = dynamic_cast<Unit&>(*(p1.getField()[i]));
      return target;
    }
    else if (player == 2) {
      Unit& target = dynamic_cast<Unit&>(*(p2.getField()[i]));
      return target;
    }
    else {
      Unit& target = dynamic_cast<Unit&>(*(nonActivePlayer->getField()[i]));
      return target;
    }
}

Player* Board::getActivePlayer() const {
  return activePlayer;
}

const Player* Board::getPlayer(int i) const {
  if (i == 1) return &p1;
  else return &p2;
}
