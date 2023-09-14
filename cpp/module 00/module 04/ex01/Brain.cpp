#include "Brain.hpp"

Brain::Brain()
{

}

Brain::Brain(const Brain &brain)
{
	*this = brain;
}

Brain& Brain::operator=(const Brain &brain)
{

	return (*this);
}

Brain::~Brain()
{

}