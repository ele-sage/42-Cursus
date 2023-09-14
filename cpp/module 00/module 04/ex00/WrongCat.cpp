#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	*this = wrongcat;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
	if (this != &wrongcat)
		this->_type = wrongcat._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}
