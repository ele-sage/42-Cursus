#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class ICharacter;

class AMateria
{
protected:
    string _type;

public:
    AMateria();
    AMateria(string const & type);
    AMateria(const AMateria &copy);
    AMateria& operator=(const AMateria &copy);
    virtual ~AMateria();

    string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif