#include "DiamondTrap.hpp"

//color: Blue
static void printClassName()
{
	std::cout << "\033[1;34m[DiamondTrap]\033[0m ";
}

DiamondTrap::DiamondTrap() : ClapTrap(), _name("default")
{
	printClassName();
	std::cout << "constructor created : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitpoints = FragTrap::_hitpoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	printClassName();
	std::cout << "constructor created : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
	*this = diamondtrap;
	printClassName();
	std::cout << "copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	_name = diamondtrap._name;
	_hitpoints = diamondtrap._hitpoints;
	_energyPoints = diamondtrap._energyPoints;
	_attackDamage = diamondtrap._attackDamage;
	printClassName();
	std::cout << "assignation operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	printClassName();
	std::cout << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	printClassName();
	std::cout << _name << std::endl;
}
