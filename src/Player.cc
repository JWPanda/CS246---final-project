#include "Player.h"
#include "Minion.h"
#include "Board.h"
#include <string>
#include <random>
#include <iostream>

using namespace std;

Factory Player::myFactory;

Player::Player(string Name, ifstream &deck, int playerNum, Board& theBoard, bool testing) : number{playerNum}, myFace{make_shared<Face>(Name, this)}, theBoard{theBoard} {
    string s;

    while (getline(deck, s)) {
      myDeck.emplace_back(myFactory.makeCard(s, this));
    }

    if (!testing) shuffleDeck();

    for (int i = 0; i < 4; ++i)  {
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
    myFace->incMana();
    myFace->refillMana();
    for(auto c: myField) {
      dynamic_pointer_cast<Unit>(c)->grantAction();
    }
}

void Player::shuffleDeck() {
    std::random_device rd;  //Get seed for random number
    std::mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, myDeck.size()-1);
    for (unsigned int i = 0; i < myDeck.size() * 10; ++i)
    {
      int j = distribution(gen), k = distribution(gen);
      swap(myDeck[j], myDeck[k]);
    }
}

// Check Trigger:
void Player::checkTrigger(Ability::AbilityType trigger, shared_ptr<Unit> target) {
    for (unsigned int i = 0 ; i < myField.size(); ++i) {
        if (myField[i]->checkAbility() == trigger) {
          myField[i]->use(theBoard, target);
        }
    }
    if (myRitual.size() && myRitual.front()->checkAbility() == trigger)
    {
      myRitual.front()->use(theBoard, target);
    }
}



//Game Commands-----------------------------------------------------------------
void Player::play (int i, int p, int t ) {
    int handSize = myHand.size();
    if (i + 1 > handSize)
    {
      if (handSize) throw "Error: you only have "s + to_string(handSize) + " cards in your hand"s;
      throw "Error: you have no cards in your hand."s;
    }
    if (myField.size() == 5) throw "Error: there are already 5 cards on your field"s;
    int cost = myHand[i]->getCost();
    int curMana = myFace->getCurrentMana();
    if (cost > curMana) throw "Error: not enough mana"s;
    else {
        myHand[i]->play(theBoard, i, p, t);
        myFace->spendMana(cost);
        myHand.erase(myHand.begin()+i);
    }
}

void Player::use(int i , int p, int t) {
    if (myField[i]->checkAbility() != Ability::NONE) throw "Error: "s + myField[i]->getName() + " has no ability"s;
    int curMana = myFace->getCurrentMana();
    int cost = myField[i]->getAbilityCost();
    if (cost > curMana) throw "Error: not enough mana to use "s + myField[i]->getName() +  "'s ability"s;
    else {
       myField[i]->use(theBoard, p , t);
       myFace->spendMana(cost);
   }
}

void Player::attack(int m1, shared_ptr<Unit>target) {
    shared_ptr<Unit> attacker = dynamic_pointer_cast<Unit>(myField[m1]);
    attacker->attack(target);
}



//Move Methods----------------------------------------------------------------
void Player::moveToGraveyard (shared_ptr<Unit> self) {
  int index = findSelf(self, myField);
  if (index < 0) throw "Error: card not found on field";
  myGraveyard.emplace_back(self);
  myField.erase(myField.begin() + index);
  theBoard.checkTrigger(Ability::DEATH, self);
}

void Player::moveToBoard(shared_ptr<Unit> self) {
  int fieldSize = myField.size();
  if (fieldSize == 5) throw "Error: there are already 5 cards on your field"s;
  myField.emplace_back(self);
  theBoard.checkTrigger(Ability::ENTER, self);
}

void Player::destroyRitual() {
  if (!myRitual.size()) throw "Error: ritual field is empty"s;
  myRitual.erase(myRitual.begin());
}

void Player::moveToRitual(int i) {
  if (myRitual.size() > 0) destroyRitual();
  myRitual.emplace_back(myHand[i]);
}

void Player::moveToDeck(shared_ptr<Card> self) {
  int index = findSelf(self, myField);
  if (index < 0) throw "Error: card not found on field"s;
  myDeck.emplace_back(self);
  myField.erase(myField.begin() + index);
}

void Player::placeEnchantment(shared_ptr<Card> self) {
  int fieldi = findSelf(self, myField);
  if (fieldi < 0) throw "Error: card not found on field"s;
  swap(myField[fieldi], self);
}

void Player::revive() {
  if (!myGraveyard.size()) throw "Error: graveyard is empty"s;
  moveToBoard (myGraveyard.back());
  myGraveyard.pop_back();
}

void Player::disenchant(shared_ptr<Card> self) {
  shared_ptr<Unit> base = self->getBase();
  shared_ptr<Unit> enchanted = dynamic_pointer_cast<Unit>(self);
  swap (enchanted, base);
}


void Player::discard(int i) {
  int handSize = myHand.size();
  if (i > handSize) throw "Error: there are only "s + to_string(myHand.size()) + " cards in your hand"s;
  myHand.erase(myHand.begin()+i);
}



// Accessors--------------------------------------------------------------------
void Player::gainMana(int m) {
  myFace->gainMana(m);
}

int Player::getMana() const{
  return myFace->getCurrentMana();
}

int Player::getNumber() const {
  return number;
}

shared_ptr<Face> Player::getFace() {
  return myFace;
}

const shared_ptr<Card> Player::getGraveyard() const{
  if (myGraveyard.empty()) return nullptr;
  return myGraveyard.back();
}

const shared_ptr<Card> Player::getRitual() const{
  if (myRitual.empty()) return nullptr;
  return myRitual.front();
}

const vector<shared_ptr<Card>>& Player::getHand() const{
  return myHand;
}

const vector<shared_ptr<Card>>& Player::getField() const{
  return myField;
}



//Helper Functions--------------------------------------------------------------
int Player::findSelf(shared_ptr<Card> self, const vector<shared_ptr<Card>> &cvec) {
  for (unsigned int i = 0; i < cvec.size(); ++i) {
    shared_ptr<Card> selfBase, vecBase;
    if (self->getBase())
    {
      selfBase = self->getBase();
      while (selfBase->getBase())
      {
        selfBase = selfBase->getBase();
      }
    }
    if (cvec[i]->getBase())
    {
      vecBase = cvec[i]->getBase();
      while (vecBase->getBase())
      {
        vecBase = vecBase->getBase();
      }
    }
    if ((selfBase && vecBase && selfBase == vecBase) || (selfBase && selfBase == cvec[i]) ||
      (vecBase && vecBase == self) || (self == cvec[i])) return i;
  }
  return -1;
}
