#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <Unit.h>


class Enchantment : public Unit
{
    public:
        Enchantment(int cost,int Attack, int Defense, Player* player);
        virtual ~Enchantment();
        virtual Enchantment * enchant(Unit& target); // enchant target and produce pointer to be placed on the field

        std::string getDescription() override;
        int getEnchantmentAttack() override;
        int getEnchantmentDefense() override;

        void die() override();
        CardType getType() override;

    protected:
        Unit* base;
    private:
};

struct giantStrength : public Enchantment {
    giantStrength(Player* player);
    std::string getEnchantmentDescription() override;
    Enchantment * enchant(Unit& target) override;
};

struct magicFatigue : public Enchantment {
    magicFatigue(Player* player);
    std::string getEnchantmentDescription() override;
    int getAbilityCost() override;
}

struct silence : public Enchantment {
    silence(Player* player);
    std::string getEnchantmentDescription() override;
    bool hasAbility() override;
};
#endif // ENCHANTMENT_H
