#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "Ability.h"
#include "Unit.h"


class Enchantment : public Unit
{
    public:

        //Ctor and Dtor:
        Enchantment(int cost,int Attack, int Defense, Player* player);
        virtual ~Enchantment();

        //Game Mechanics:
        void die() override;
        void play (Board& theBoard, int i, int p, int t) override;
        virtual void enchant(std::shared_ptr<Unit> target); // enchant target and produce pointer to be placed on the field
        void unsummon(); // Unsummons the enchantment
        void disenchant() override;

        //Accessors
        CardType getType() const override;
        std::string getName() const override;
        std::string getDescription() const override;
        std::shared_ptr<Unit> getBase() override;
        int getEnchantmentCost() const override;
        int getEnchantmentAttack() const override;
        int getEnchantmentDefense() const override;

    protected:
        // TODO make this a smart pointer
        std::shared_ptr<Unit> base;
        int enchantmentCost;
};


// Enchantment structures:
struct GiantStrength : public Enchantment {
    GiantStrength(Player* player);
    std::string getEnchantmentName() const override;
    void enchant(std::shared_ptr<Unit> target) override;
};

struct MagicFatigue : public Enchantment {
    MagicFatigue(Player* player);
    std::string getEnchantmentName() const override;
    std::string getEnchantmentDescription() const override;
    int getAbilityCost() const override;
};

struct Silence : public Enchantment {
    Silence(Player* player);
    std::string getEnchantmentName() const override;
    std::string getEnchantmentDescription() const override;
    Ability::AbilityType checkAbility() const override;
};

struct Aura : public Enchantment {
    Aura(Player* player);
    std::string getEnchantmentName() const override;
    std::string getEnchantmentDescription() const override;
    void enchant(std::shared_ptr<Unit> target) override;
    std::string getDescription() const override;
};

#endif // ENCHANTMENT_H
