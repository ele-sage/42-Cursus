#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	cout << "Cat default constructor called" << endl;
	_brain = new Brain();
	if (!_brain)
		cout << "Error: memory allocation failed" << endl;
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
	cout << "Cat copy constructor called" << endl;
}

Cat& Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->_type = cat._type;
		this->_brain = new Brain(*cat._brain);
		if (!_brain)
			cout << "Error: memory allocation failed" << endl;
	}
	cout << "Cat assignation operator called" << endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "Meow" << endl;
}
