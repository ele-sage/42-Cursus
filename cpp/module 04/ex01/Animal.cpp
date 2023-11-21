#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	_type = "Animal";
	cout << "Animal default constructor called" << endl;
}

Animal::Animal(std::string type) : _type(type)
{
	cout << "Animal type constructor called" << endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	cout << "Animal copy constructor called" << endl;
}

Animal& Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->_type = animal._type;
	cout << "Animal assignation operator called" << endl;
	return (*this);
}

Animal::~Animal()
{
	cout << "Animal destructor called" << endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
