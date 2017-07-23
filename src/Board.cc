#include "Board.h"
using namespace std;

Board::Board(string name1, string name2, ifstream &deck1, ifstream &deck2) : p1{name1,deck1}, p2{name2, deck2}, activePlayer{nullptr}, nonActivePlayer{nullptr} {}

Board::~Board() {
    delete activePlayer;
    delete nonActivePlayer;
}

void Board::changeTurn () {
    // checks end turn trigger for active player which only occurs if it is not the first turn.
    if (activePlayer != nullptr) //TODO checkTrigger(2);
    if (activePlayer == nullptr || activePlayer == &p1) {// turn change for p1 or turn 2
        activePlayer = &p2;
        nonActivePlayer = &p1;
    }
    else {// turn change for p2
        activePlayer = &p1;
        nonActivePlayer = &p2;
    }
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

Player* Board::getActivePlayer() {
    return activePlayer;
}*/

void Board::play (int i) {
    activePlayer->play(i);
}

/* TODO!!!!! void Board::play (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field

    activePlayer.play(this, i , p ,t);
}

void Board::use (int i) {
    activePlayer.use(this, i);
}

void Board::use (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field

    activePlayer.use(this, i, p, t)
}

void Board::attack (int m1, int m2) {
    if (m2 != -1) { //  attack an enemy minon
        Unit &target = *nonActivePlayer.field[m2]; // not sure if i can pass a card reference here
        activePlayer.attack(m1, target);
    } else { // attack the enemy face
    activePlayer.attack(m1, nonActivePlayer.face);
    }
}*/

<<<<<<< HEAD
Card & Board::getMinion (int i , int player) {
    if (player == 0) {
      Card &target = *activePlayer->getField()[i];
      return target;
=======
//TODO fix this here
void Board::checkTrigger(int trigger) {
    // 1 = beginning of turn
    // 2 = end of turn
    // 3 = minion is played
    // 4 = minion dies
    if (trigger == 1 || trigger == 2) {
        activePlayer.checkTrigger(this, trigger)
>>>>>>> 9718b3f827632b0dba8bd4124f7b1631b6d0d88a
    }
    else if (player == 1){
      Card &target = *p1.getField()[i];
      return target;
    }
    else if (player == 2) {
      Card &target = *p2.getField()[i];
      return target;
    }
}

Player* Board::getActivePlayer() {
  return activePlayer;
}
