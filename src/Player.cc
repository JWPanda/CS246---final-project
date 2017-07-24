#include "Player.h"
#include "Minion.h"
#include <string>

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

//Turn logistics methods------------------------------------------------------
void Player::draw() {
    if (myDeck.size() == 0) throw "Error: cannot draw card as deck is empty"s;
    if (myHand.size() == 5) throw "Error: cannot draw card as hand is full"s;
    myHand.emplace_back(myDeck[0]);
    myDeck.erase(myDeck.begin());
}

void Player::newTurn() {
    if (!(!myDeck.size() == 0 && myHand.size() == 5)) draw();
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
    if (!(field[i].hasAbility()) throw "Error: " field[i]->getName() " has no ability";
    int curMana = myFace.getCurrentMana();
    int cost = field[i].getAbilityCost();
    if (cost > curMana) throw "Error: not enough mana to play " field[i]->getName() "'s ability";
    else {
       field[i].use(theBoard, p , t);
       myFace.spendMana(cost);
   }
}*/

void Player::attack(int m1, Unit &target) {
    Unit* attacker = dynamic_cast<Unit*>(myField[m1]);
    attacker->attack(target);
}


//Move Functions:-----------------------------------------------------------
void Player::play (Board &theBoard, int i, int p, int t ) {
    int handSize = myHand.size();
    if (i + 1 > handSize) throw "Error: you only have "s + to_string(handSize) + " cards in your hand"s;
    if (myField.size() == 5) throw "Error: there are already 5 cards on your field"s;
    int cost = myHand[i]->getCost();
    int curMana = myFace.getCurrentMana();
    if (cost > curMana) throw "Error: not enough mana"s;
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
  if (fieldSize == 5) throw "Error: there are already 5 cards on your field"s;
  myField.emplace_back(myHand[i]);
  myHand.erase(myHand.begin()+i);
}

void Player::destroyRitual() {
  if (!myRitual.size()) throw "Error: ritual field is empty"s;
  myRitual.erase(myRitual.begin());
}

void Player::moveToRitual(int i) {
  if (myRitual.size() > 0) destroyRitual();
  myRitual.emplace_back(myHand[i]);
  myHand.erase(myHand.begin() + i);
}

void Player::moveToDeck(Card* self) {
  int index = findSelf(self, myField);
  myDeck.emplace_back(self);
  myField.erase(myField.begin() + index);
}

void Player::placeEnchantment(Card* self) {
  int handi = findSelf(self, myHand);
  swap(myField[handi], self);
  myHand.erase(myHand.begin() + handi);
}

void Player::discard(int i) {
  int handSize = myHand.size();
  if (i > handSize) throw "Error: there are only "s + to_string(myHand.size()) + " cards in your hand"s;
  myHand.erase(myHand.begin()+i);
}

// Accessors--------------------------------------------------------------------
int Player::getMana() const{
  return myFace.getCurrentMana();
}

Face* Player::getFace() {
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

//Helper Functions--------------------------------------------------------------
int Player::findSelf(Card* self, vector<Card*> cvec) {
  for (unsigned int i = 0; i < cvec.size(); ++i) {
    if (cvec[i] == self) return i;
  }
    return -1;
}
