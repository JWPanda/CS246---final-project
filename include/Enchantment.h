#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <Unit.h>


class Enchantment : public Unit
{
    public:
        Enchantment(int cost,int Attack, int Defense, Player* player);
        virtual ~Enchantment();

        void play (Board& theBoard, int i, int p, int t) override;
        virtual void enchant(Unit& target); // enchant target

        std::string getName() override;
        std::string getDescription() override;

        int getEnchantmentAttack() override;
        int getEnchantmentDefense() override;

        void die() override();
        int getType() override;

    protected:
        Unit* base;
    private:
};

struct giantStrength : public Enchantment {
    giantStrength(Player* player);
    std::string getEnchantmentDescription() override;
    std::string getEnchantmentName() override;
    Enchantment * enchant(Unit& target) override;
};

struct magicFatigue : public Enchantment {
    magicFatigue(Player* player);
    std::string getEnchantmentDescription() override;
    std::string getEnchantmentName() override;
    int getAbilityCost() override;
}

struct silence : public Enchantment {
    silence(Player* player);
    std::string getEnchantmentDescription() override;
    std::string getEnchantmentName() override;
    bool hasAbility() override;
};
#endif // ENCHANTMENT_H
