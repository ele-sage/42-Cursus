#include "FragTrap.hpp"

//color: red
static void printClassName()
{
	std::cout << "\033[1;31m[FragTrap]\033[0m";
}

FragTrap::FragTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	printClassName();
	std::cout << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	printClassName();
	std::cout << " constructor created : " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
	*this = fragtrap;
	printClassName();
	std::cout << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &fragtrap)
{
	_name = fragtrap._name;
	_hitpoints = fragtrap._hitpoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;
	printClassName();
	std::cout << " assignation operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	printClassName();
	std::cout << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	printClassName();
	std::cout << " " << _name << " has requested a high five!" << std::endl;
}