#include "Player.h"
using namespace std;

Player::Player(string Name, ifstream &deck): myFace{Name, this} {
    string s; 
    while (deck>>s) {
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

void Player::attack(int m1 ,Unit &target) {
    myField[m1]->attack(target);
}

void Player::use(Board &theBoard, int i , int p, int t) {
    if (!(myField[i]->hasAbility())) throw;
    int curMana = myFace.getCurrentMana();
    int cost = myField[i]->getAbilityCost();
    if (cost > curMana) throw;
    else {
       myField[i]->use(theBoard, p , t);
       myFace.spendMana(cost);
   }
}

void Player::newTurn() {
    draw();
    myFace.incMana();
    myFace.refillMana();
}

//void Player::checkTrigger(int trigger) { TODO
//    for (int i = 0 ; i < myField.size(); ++i) {
//        if (myField[i]->isTriggered()); // use the card some how
//    }
    //ritual.use(trigger);
//}

void Player::play (int i) {
    if (i + 1 > myHand.size()) throw; 
    if (myField.size() == 5) throw;
    int cost = myHand[i]->getCost();
        int curMana = myFace.getCurrentMana();
    if (cost > curMana) throw;
    else {
        if (myHand[i]->getType() == 1) {
            myField.emplace_back(myHand[i]);
            myHand.erase(myHand.begin());//*********** TODO fix this
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

void Player::play (int i, Unit &target) {
    if (i + 1 > myHand.size()) throw;
    if (myField.size() == 5) throw;
    int cost = myHand[i]->getCost();
    int curMana = myFace.getCurrentMana();
    if (cost > curMana)  throw;
    //else {
    //   hand[i].play(i, target);
    //}
    myFace.spendMana(cost);
}
