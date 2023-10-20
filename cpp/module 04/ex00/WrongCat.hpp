#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
    WrongCat();
    WrongCat(const WrongCat &wrongcat);
    WrongCat& operator=(const WrongCat &wrongcat);
    ~WrongCat();

    void makeSound() const;
};

#endif
