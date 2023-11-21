#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria        *_materia[4];

    void deleteMateria(AMateria **materia);
public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource& operator=(const MateriaSource &copy);
    ~MateriaSource();

    void learnMateria(AMateria*);
    AMateria* createMateria(string const & type);
};

#endif