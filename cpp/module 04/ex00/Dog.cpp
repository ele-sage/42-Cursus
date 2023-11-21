#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	cout << "Dog default constructor called" << endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
	cout << "Dog copy constructor called" << endl;
}

Dog& Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		this->_type = dog._type;
	cout << "Dog assignation operator called" << endl;
	return (*this);
}

Dog::~Dog()
{
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
