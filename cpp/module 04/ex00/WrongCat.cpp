#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	*this = wrongcat;
	cout << "WrongCat copy constructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
	if (this != &wrongcat)
		this->_type = wrongcat._type;
	cout << "WrongCat assignation operator called" << endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called" << endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}
