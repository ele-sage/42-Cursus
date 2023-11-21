#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	_type = "WrongAnimal";
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	cout << "WrongAnimal type constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	*this = wronganimal;
	cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	if (this != &wronganimal)
		this->_type = wronganimal._type;
	cout << "WrongAnimal assignation operator called" << endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called" << endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
