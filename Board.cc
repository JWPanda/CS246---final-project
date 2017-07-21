#include "Board.h"
using namespace std;

Board::Board(Player* p1, Player *p2, Player *activePlayer, Player *nonActivePlayer) : p1{p1}, p2{p2}, activePlayer{nullptr}, nonActivePlayer{nullptr} {}

Board::~Board() {
    delete p1;
    delete p2;
    delete activePlayer;
    delete nonActivePlayer;
}

void Board::changeTurn () {
    // checks end turn trigger for active player which only occurs if it is not the first turn. 
    if (activePlayer != nullptr) checkTrigger(2);
    if (activePlayer == nullptr || activePlayer == p1) {// turn change for p1 or turn 2 
        activePlayer = p2;
        nonActivePlayer = p1;
    }
    else {// turn change for p2  
        activePlayer = p1;
        nonActivePlayer = p2;
    }
    activePlayer.newTurn(); // initiates new turn for active player
    checkTrigger(1); // check new turn trigger for active player
}

void Board::play (int i) {
    activePlayer.play(i); 
    checkTrigger(3); // trigger check for playing a minion
}

void Board::play (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field
    
    // case where the target is on player 1's field
    if (p == 1) { 
        activePlayer.play(i, p1.field[t]);
    }
    // case where the target is on player 2's field
    if (p == 2) {
        activePlayer.play(i, p2.field[t]);
    }
}

void Board::use (int i) {
    activePlayer.use(i);
}

void Board::use (int i, int p, int t) {
    // i = the index of the card in the hand that will be played.
    // p = the owner of the target ie: p1 or p2
    // t = the location of the target on the player's field
    
    // case where the target is on player 1's field
    if (p == 1) {
        activePlayer.use(i, p1.field[t]) 
    }
    // case where the target is on player 2's field
    if (p == 2) {
        activePlayer.use(i, p2.field[t]) 
    }
}

void Board::attack (int m1, int m2 = -1) {
    if (m2 != -1) { //  attack an enemy minon
        Card& target = nonActivePlayer.field[m2]; // not sure if i can pass a card reference here
        activePlayer.attack(m1, target);
    } else { // attack the enemy face
    activePlayer.attack(m1, nonActivePlayer.face);
    }
}

void Board::inspect(int m1) {
    activePlayer.inspect(m1);
}

void Board::checkTrigger(int trigger) {
    // 1 = beginning of turn
    // 2 = end of turn
    // 3 = minion is played
    // 4 = minion dies
    if (trigger == 1 || trigger == 2) {
        activePlayer.checkTrigger(trigger)
    }
    else {
        activePlayer.checkTrigger(trigger);
        nonActivePlayer.checkTrigger(trigger);
    }
}

