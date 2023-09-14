#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondtrap);
    DiamondTrap& operator=(const DiamondTrap &diamondtrap);
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack;
};

#endif