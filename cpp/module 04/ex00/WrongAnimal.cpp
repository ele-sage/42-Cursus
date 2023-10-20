#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{

}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	*this = wronganimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	if (this != &wronganimal)
		this->_type = wronganimal._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{

}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
