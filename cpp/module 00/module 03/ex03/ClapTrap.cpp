#include "ClapTrap.hpp"

static void printClassName()
{
	std::cout << "\033[1;33m[ClapTrap]\033[0m";
}

ClapTrap::ClapTrap() : _name("default"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	printClassName();
	std::cout << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	printClassName();
	std::cout << " constructor created : " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	printClassName();
	std::cout << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	_name = claptrap._name;
	_hitpoints = claptrap._hitpoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
	printClassName();
	std::cout << " assignation operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	printClassName();
	std::cout << " " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (_energyPoints > 0 && _hitpoints > 0)
	{
		printClassName();
		std::cout << " " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitpoints == 0)
	{	
		printClassName();
		std::cout << " " << _name << " can't attack, it's already dead!" << std::endl;
	}
	else
	{
		printClassName();
		std::cout << " " << _name << " has no energy left!" << std::endl;
	}
}

void ClapTrap::takeDamage(int amount)
{
	if (_hitpoints - amount > 0)
	{
		printClassName();
		std::cout << " " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitpoints -= amount;
	}
	else if (_hitpoints == 0)
	{
		printClassName();
		std::cout << " " << _name << " can't take damage, it's already dead!" << std::endl;
	}
	else
	{
		printClassName();
		std::cout << " " << _name << " takes " << amount << " points of damage!" << std::endl;
		printClassName();
		std::cout << " " << _name << " is dead!" << std::endl;
		_hitpoints = 0;
	}
}

void ClapTrap::beRepaired(int amount)
{
	if (_energyPoints > 0 && _hitpoints > 0)
	{
		printClassName();
	std::cout << " " << _name << " is repaired by " << amount << " points!" << std::endl;
		_energyPoints--;
		_hitpoints += amount;
	}
	else if (_hitpoints == 0)
	{
		printClassName();
		std::cout << " " << _name << " can't be repaired, it's already dead!" << std::endl;
	}
	else
	{
		printClassName();
		std::cout << " " << _name << " has no energy left!" << std::endl;
	}
}