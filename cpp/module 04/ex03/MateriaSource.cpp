#include "MateriaSource.hpp"

void	MateriaSource::deleteMateria(AMateria **materia)
{
	for (int i = 0; i < 4; i++)
		if (materia[i])
			delete materia[i];
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		deleteMateria(_materia);
		for (int i = 0; i < 4; i++)
		{
			if (copy._materia[i])
				_materia[i] = copy._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	deleteMateria(_materia);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	return (0);
}
