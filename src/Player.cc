#include "Player.h"
using namespace std;

Player::Player(String Name, ifstream &deck): player{Name} {
    string s; 
    while (ifstream>>s) {
        if (s == "Air Elemental") {
            deck.emplace_back(new AirElemental(this));
        }   
    }
    for (int i = 0; i < 5; ++i)  {
        if(deck.size() == 0) break;
        draw();
    }
}

Player::~Player() {}

void draw() {
    if (hand.size() == 5) throw;
    hand.emplace_back(deck[1]);
    deck.erase(myvector.begin());
}

void attack(int m1 ,Unit &target) {
    field[m1].attack(target);
}

<<<<<<< HEAD
void use(int m1, Board &theBoard) {
    hand[m1].use(theBoard);
}

void use(int m1, Unit &target) {
    hand[m1].use(target);
}

void inspect(int i) {
    // something with display... not sure what you want to do here iggy
=======
void use(Board &theBoard, int i , int p, int t) {
    if (!(field[i].hasAbility()) throw;
    int curMana = Face.getCurrentMana();
    int cost = field[i].getAbilityCost();
    if (cost > curMana) throw;
    else {
       field[i].use(theBoard, p , t);
       Face.spendMana(cost);
   }
>>>>>>> 818b437e2db06043d38b2da008969ed3efd086ea
}

void newTurn() {
    draw();
    Face.incMana();
    Face.refillMana();
}

void checkTrigger(int trigger) {
    for (int i = 0 ; i < board.size(); ++i) {
        if (field[i].isTriggered) // use the card some how
    }
    //ritual.use(trigger);
}

void play (int i ) {
    if (i + 1 > hand.size()) throw; 
    if (field.size() = 5) throw;
    int cost = hand[i].getCost();
    int curMana = Face.getCurrentMana();
    if (cost > curMana) throw;
    else {
        if (hand[i].getType() == 1) {
            field.emplace_back(hand[i]);
            hand.erase(i);
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
        Face.spendMana(cost);
    }
}

void play (int i, Unit &target) {
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
