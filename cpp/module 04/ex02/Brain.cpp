#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain default constructor called" << endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
	cout << "Brain copy constructor called" << endl;
}

Brain& Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
	cout << "Brain assignation operator called" << endl;
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain destructor called" << endl;
}
