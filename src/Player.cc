#include "Player.h"
#include "Minion.h"
#include <iostream>

using namespace std;

Factory Player::myFactory;

Player::Player(string Name, ifstream &deck):myFace{Name, this} {
    string s;

    while (getline(deck, s)) {
      myDeck.emplace_back(myFactory.makeCard(s, this));
    }

    for (int i = 0; i < 5; ++i)  {
        if(myDeck.size() == 0) break;
        draw();
    }
}

Player::~Player() {}

//Turn logistics methods--------------------------------------------------------

void Player::draw() {
    if (myDeck.size() == 0) return; // put a throw here
    if (myHand.size() == 5) return; // put a throw here
    myHand.emplace_back(myDeck[0]);
    myDeck.erase(myDeck.begin());
}

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

/*
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

 TODO void Player::attack(int m1 ,Unit &target) {
    myField[m1].attack(target);
}

*/

//Move Functions:---------------------------------------------------------------
void Player::play (Board &theBoard, int i, int p, int t ) {
    int handSize = myHand.size();
    if (i + 1 > handSize) throw;
    int cost = myHand[i]->getCost();
    int curMana = myFace.getCurrentMana();
    if (cost > curMana) throw;
    else {
        myHand[i]->play(theBoard, i, p, t);
        myFace.spendMana(cost);
    }
}

//Move Functions----------------------------------------------------------------
void Player::moveToGraveyard (Card* self) {
  myGraveyard.emplace_back(self);
  for (unsigned int i = 0; i < myField.size(); ++i) {
    if (myField[i] == self) myField.erase(myField.begin()+i);
  }
}

void Player::moveToBoard(int i) {
  int fieldSize = myField.size();
  if (fieldSize == 5) throw;
  myField.emplace_back(myHand[i]);
  myHand.erase(myHand.begin()+i);
}

void Player::moveToRitual(int i) {
  if (myRitual.size() > 0) myRitual.erase(myRitual.begin());
  myRitual.emplace_back(myHand[i]);
  myHand.erase(myHand.begin()+i);
}

void Player::discard(int i) {
  myHand.erase(myHand.begin()+i);
}

// Accessors--------------------------------------------------------------------
int Player::getMana() const{
  return myFace.getCurrentMana();
}

const Face* Player::getFace() const{
  return &myFace;
}

const Card* Player::getGraveyard() const{
  if (myGraveyard.empty()) return nullptr;
  return myGraveyard.back();
}

const Card* Player::getRitual() const{
  if (myRitual.empty()) return nullptr;
  return myRitual.front();
}

const vector<Card*>& Player::getHand() const{
  return myHand;
}

const vector<Card*>& Player::getField() const{
  return myField;
}
