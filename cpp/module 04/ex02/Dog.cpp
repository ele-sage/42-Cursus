#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	cout << "Dog default constructor called" << endl;
	_brain = new Brain();
	if (!_brain)
		cout << "Error: memory allocation failed" << endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
	cout << "Dog copy constructor called" << endl;
}

Dog& Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog._type;
		this->_brain = new Brain(*dog._brain);
		if (!_brain)
			cout << "Error: memory allocation failed" << endl;
	}
	cout << "Dog assignation operator called" << endl;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
