#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	_type = "Animal";
}

Animal::Animal(std::string type) : _type(type)
{

}

Animal::Animal(const Animal &animal)
{
	*this = animal;
}

Animal& Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

Animal::~Animal()
{

}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
