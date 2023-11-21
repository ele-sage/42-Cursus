#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{

}

AMateria::AMateria(string const & type) : _type(type)
{

}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

AMateria::~AMateria()
{
	
}

string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria* AMateria::clone() const
{
	return (AMateria *)this;
}

