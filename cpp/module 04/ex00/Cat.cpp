#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	cout << "Cat default constructor called" << endl;
}

Cat::Cat(const Cat &cat)
{
	cout << "Cat copy constructor called" << endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
	if (this != &cat)
		this->_type = cat._type;
	cout << "Cat assignation operator called" << endl;
	return (*this);
}

Cat::~Cat()
{
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "Meow" << endl;
}
