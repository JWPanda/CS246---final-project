#include "Player.h"
#include "Minion.h"
#include <iostream>
using namespace std;

Player::Player(string Name, ifstream &deck):myFace{Name, this} {
    string s;
    while (getline(deck, s)) {
        if (s == "Air Elemental") {
            myDeck.emplace_back(new AirElemental(this));
        }
    }
    for (int i = 0; i < 5; ++i)  {
        if(myDeck.size() == 0) break;
        draw();
    }
}

Player::~Player() {}

void Player::draw() {
    if (myHand.size() == 5) throw;
    myHand.emplace_back(myDeck[1]);
    myDeck.erase(myDeck.begin());
}

/* TODO void Player::attack(int m1 ,Unit &target) {
    myField[m1].attack(target);
}


void Player::use(int m1, Board &theBoard) {
    myHand[m1].use(theBoard);
}

void Player::use(Board &theBoard, int i , int p, int t) {
    if (!(field[i].hasAbility()) throw;
    int curMana = myFace.getCurrentMana();
    int cost = field[i].getAbilityCost();
    if (cost > curMana) throw;
    else {
       field[i].use(theBoard, p , t);
       myFace.spendMana(cost);
   }
}
*/

void Player::newTurn() {
    draw();
    myFace.incMana();
    myFace.refillMana();
}

/* TODO void Player::checkTrigger(int trigger) {
    for (int i = 0 ; i < board.size(); ++i) {
        if (field[i].isTriggered) // use the card some how
    }
    //ritual.use(trigger);
}
*/

void Player::play (int i ) {
    int handSize = myHand.size();
    int fieldSize = myField.size();
    if (i + 1 > handSize) throw;
    if (fieldSize == 5) throw;
    int cost = myHand[i]->getCost();
    int curMana = myFace.getCurrentMana();
    if (cost > curMana) throw;
    else {
        if (myHand[i]->getType() == 1) {
            myField.emplace_back(myHand[i]);
            myHand.erase(myHand.begin());
        }
        //else if (hand[i].getType() == 2) {
        //    hand[i].use(stuff here);
        //    hand.erase(i);
        //}
        //else if (hand[i].getType() == 3) {
        //    ritual.erase(ritual.being());
        //    ritual.emplace_back(hand[i]);
        //    hand.erase(i);
        //}
        //else if do enchantment here !!!!!!!
        myFace.spendMana(cost);
    }
}

/* TODO void Player::play (int i, Unit &target) {
    if (i + 1 > hand.size()) throw;
    if (field.size() = 5) throw;
    int cost = hand[i].getCost();
    int curMana = Face.getCurrentMana();
    if (cost > curMana)  throw;
    //else {
    //   hand[i].play(i, target);
    //}
    Face.spendMana();
}
*/
const vector<Card*>& Player::getHand() {
  return myHand;
}

const vector<Card*>& Player::getField() {
  return myField;
}

Face* Player::getFace() {
  return &myFace;
}
