#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
    Cure();
    Cure(const Cure &cure);
    Cure& operator=(const Cure &cure);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif