#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
}

Dog& Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		this->_type = dog._type;
	return (*this);
}

Dog::~Dog()
{
	
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
