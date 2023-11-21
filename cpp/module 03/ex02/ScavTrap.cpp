#include "ScavTrap.hpp"

//color: green
static void printClassName()
{
	std::cout << "\033[1;32m[ScavTrap] \033[0m ";
}

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	printClassName();
	std::cout << "default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	printClassName();
	std::cout << "constructor created : " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
	*this = scavtrap;
	printClassName();
	std::cout << "copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap)
{
	_name = scavtrap._name;
	_hitpoints = scavtrap._hitpoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	printClassName();
	std::cout << "assignation operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	printClassName();
	std::cout << "destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (_energyPoints > 0 && _hitpoints > 0)
	{
		printClassName();
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitpoints == 0)
	{
		printClassName();
		std::cout  << _name << " can't attack, it's already dead!" << std::endl;
	}
	else
	{
		printClassName();
		std::cout << _name << " has no energy left!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	printClassName();
	std::cout << "" << _name << " has entered in Gate keeper mode." << std::endl;
}