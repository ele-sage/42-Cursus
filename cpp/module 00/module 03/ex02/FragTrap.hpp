#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &fragtrap);
    FragTrap& operator=(const FragTrap &fragtrap);
    ~FragTrap();

    void highFivesGuys();
};

#endif