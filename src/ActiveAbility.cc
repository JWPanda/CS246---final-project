#include "ActiveAbility.h"
#include <iostream>
using namespace std;

~ActiveAbility();

//Ctor
ActiveAbility::ActiveAbility(int cost) : Ability{cost} {};


int ActiveAbility::isTriggered() { return -1};



// Minion Abilities
// Novice Pyromancer
NovicePyromancer_Ability::NovicePyromancer_Ability()
 : ActiveAbility{1} {};

 void NovicePyromancer_Ability::use(Board& theBoard, int p , int t, Player* myPlayer) {
     theBoard.getMinion(t,p)->getHit(1);
 }

string NovicePyromancer_Ability::getDescription() {
    return "Deal 1 damage to target minion";
};

// Apprentice Summoner
ApprenticeSummoner_Ability::ApprenticeSummoner_Ability()
 : ActiveAbiilty{1} {};

void ApprenticeSummoner_Ability::use(Board& theBoard, int p , int t, Player* myPlayer) {
    cout << "use Apprentice Summoner_Ability" << endl;
    // check if player field is full, if so throw an exception
    //if (myPlayer->getField().size() >= 5) { throw;}
    // if board is not full, create an air elemental on board
    //shared_ptr<Card> create = make_shared<AirElemental>();
    // add created airelemental to myPlayer's board
    // call player's check trigger for minion being summoned on new elemental
}

string ApprenticeSummoner_Ability::getDescription() {
    return "Summon a 1/1 air elemental";
};

// Master Summoner
MasterSummoner_Ability::MasterSummoner_Ability()
 : ActiveAbiilty{2} {};

void MasterSummoner_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    cout << "use Apprentice Summoner_Ability" << endl;
    // check if player field is full, if so throw an exception
    //if (myPlayer->getField().size() >= 5) { throw;}

    // loop until board is full or 3 air elementals are summoned
    //for (int i = 0, i < 3, ++1) {
    //    if (myPlayer->getField().size() >= 5) break; // someone fix this
    //shared_ptr<Card> create = make_shared<AirElemental>();
    // add created airelemental to myPlayer's board
    // call player's check trigger for minion being summoned on new elemental
    //}
}
string MasterSummoner_Ability::getDescription() {
    return "Summon up to three 1/1 air elementals"
};


// Spell Abilities
// Banish
Banish_Ability::Banish_Ability()
 : ActiveAbiilty{0} {};

void Banish_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    // if target is a ritual
    if (t == 6) {
        theBoard.getPlayer(p)->destroyRitual();
    }
    else {// target is a minion
    // if target card is a minion,
    theBoard.getMinion(t,p)->die(); // change if target is a pointer
    }
}
string Banish_Ability::getDescription() {
    return "Destroy target minion or ritual";
};

// Unsummon
Unsummon_Ability::Unsummon_Ability()
 : ActiveAbiilty{0} {};

void Unsummon_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    // idea 2:
    theBoard.getMinion(t,p,)->unsummon();
}
string Unsummon_Ability::getDescription() {
    return "Put Target minion on the bottom of its owner's deck";
};

// Recharge
Recharge_Ability::Recharge_Ability()
 : ActiveAbiilty{0} {};

void Recharge_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    // myPlayer.getRitual().increaseCharges(3); or something...
}
string Recharge_Ability::getDescription() {
    return "Your ritual gains 3 charges";
};

// Disenchant
Disenchant_Ability::Disenchant_Ability()
 : ActiveAbiilty{0} {};

void Disenchant_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    // target.disenchant();
}
string Disenchant_Ability::getDescription() {
    return "Destroy the top enchantment on target minion";
};

// Raise Dead
RaiseDead_Ability::RaiseDead_Ability()
 : ActiveAbiilty{0} {};

void RaiseDead_Ability::use(Board& theBoard, int p , int t, Player* myPlayer) {
    //myPlayer->
}
string RaiseDead_Ability::getDescription() {
    return "Resurrect the top minion on your graveyard";
};

// Blizzard
Blizzard_Ability::Blizzard_Ability()
 : ActiveAbiilty{0} {};

void Blizzard_Ability::use(Board& theBoard, int p , int t, Player* myPlayer){
    // loop through the field of each player on the borad
    // make each minion receive 2 damage
    // for (auto c : theBoard.getActivePlayer()->getField())
    //  c->getHit(2)

    // repeat about for nonActivePlayer
}
string Blizzard_Ability::getDescription() {
    return "Deal 2 damage to all minions";
};
