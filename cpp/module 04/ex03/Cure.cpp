#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &cure) : AMateria(cure)
{

}

Cure& Cure::operator=(const Cure &cure)
{
	AMateria::operator=(cure);
	return (*this);
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}