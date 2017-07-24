#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "Unit.h"


class Enchantment : public Unit
{
    public:
        Enchantment(int cost,int Attack, int Defense, Player* player);
        virtual ~Enchantment();
        virtual Enchantment * enchant(Unit& target); // enchant target and produce pointer to be placed on the field

        std::string getName() const override;
        std::string getDescription() const override;
        int getEnchantmentAttack() const override;
        int getEnchantmentDefense() const override;

        void die() override;
        CardType getType() const override;

    protected:
        Unit* base;
    private:
};

struct GiantStrength : public Enchantment {
    GiantStrength(Player* player);
    std::string getEnchantmentName() const override;
    Enchantment * enchant(Unit& target) override;
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
    bool hasAbility() const override;
};
#endif // ENCHANTMENT_H
