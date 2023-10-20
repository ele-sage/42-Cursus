#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
protected:
    std::string     _name;
    int             _hitpoints;
    int             _energyPoints;
    int             _attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &claptrap);
    ClapTrap& operator=(const ClapTrap &claptrap);
    ~ClapTrap();

    void attack(std::string const & target);
    void takeDamage(int amount);
    void beRepaired(int amount);
};

#endif