#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : virtual public ClapTrap
{
private:
    /* data */
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