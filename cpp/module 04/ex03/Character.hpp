#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    string          _name;
    AMateria        *_inventory[4];
    static int      _count;
    static AMateria **_unequipped;

public:
    Character();
    Character(string const & name);
    Character(const Character &copy);
    Character& operator=(const Character &copy);
    ~Character();

    string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void deleteUnequipped();
};

#endif