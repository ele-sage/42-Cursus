#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &scavtrap);
    ScavTrap& operator=(const ScavTrap &scavtrap);
    ~ScavTrap();

    void attack(std::string const & target);
    void guardGate();
};

#endif