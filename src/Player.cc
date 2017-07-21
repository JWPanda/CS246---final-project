#include "Player.h"
using namespace std;

Player::Player(String Name, vector<Card*> deck, vector<Card*> hand, vector<Card*graveyard>, vector<Card*> field, vector<Card*> ritual): {}

Player::~Player() {}

void draw() {
    hand.push_back(deck[1]);
    deck.erase(myvector.begin());
}

void attack(int m1 Unit &target) {
    field[m1].attack(target);
}

void use(int m1, Board &theBoard) {
    int cost = field[m1].getCost();
    if (cost > mana) throw;
    else {
        mana -= cost;
        field.use(m1, theBoard);
    }
}

void use(int m1, Unit &target) {
   int cost = field[m1].getCost();
   if (cost > mana) throw;
   else {
       mana -= cost;
       field.use(m1, theBoard);
   }
}

void inspect(int i) {
    // something with display... not sure what you want to do here iggy
}

void newTurn() {
    draw();
    ++mana;
}

void checkTrigger(int trigger) {
    for (int i = 0 ; i < board.size(); ++i) {
        field[i].checkTrigger(trigger);
    }
    ritual.checkTrigger(trigger);
}

void play (int i ) {
    int cost = hand[i].getCost();
    if (cost > mana) throw;
    else {
        mana -= cost;
        hand[i].play();
    }
}

void play (int i, Unit &target) {
    int cost = hand[i].getCost();
    if (cost > mana)  throw;
    else {
        mana-= cost;
        hand[i].play(i, target);
    }
}
