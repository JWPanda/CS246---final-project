#ifndef ACTIVEABILITY_H
<<<<<<< HEAD
#define ACTIVEABILITY_H

#include "Ability.h"


class ActiveAbility : public Ability
{
    public:
        //Ctor and Dtor:
        ActiveAbility(int cost);
        virtual ~ActiveAbility();

        // Trigger Implementation:
        int isTriggered() override;
};


// Minion Abilities
struct NovicePyromancer_Ability : public ActiveAbility
{
  NovicePyromancer_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct ApprenticeSummoner_Ability : public ActiveAbility
{
    ApprenticeSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct MasterSummoner_Ability : public ActiveAbility
{
    MasterSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

// Spell Abilities
struct Banish_Ability : public ActiveAbility
{
    Banish_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct Unsummon_Ability : public ActiveAbility
{
    Unsummon_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

#endif // ACTIVEABILITY_H
=======
#define ACTIVEABILITY_H

#include "Ability.h"


class ActiveAbility : public Ability
{
    public:
        ActiveAbility(int cost);
        virtual ~ActiveAbility();

        int isTriggered() override;


    protected:

    private:
};


// Minion Abilities
struct NovicePyromancer_Ability : public ActiveAbility {
    NovicePyromancer_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct ApprenticeSummoner_Ability : public ActiveAbility {
    ApprenticeSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct MasterSummoner_Ability : public ActiveAbility {
    MasterSummoner_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

// Spell Abilities
struct Banish_Ability : public ActiveAbility {
    Banish_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

struct Unsummon_Ability : public ActiveAbility {
    Unsummon_Ability();
    void use(Board& theBoard, int t, int p) override;
    std::string getDescription() override;
};

#endif // ACTIVEABILITY_H
>>>>>>> dc5a43d04d513daa015b55d909cc801584ee9709
