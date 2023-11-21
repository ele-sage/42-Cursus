#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

using std::cout;
using std::endl;

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &wronganimal);
    WrongAnimal& operator=(const WrongAnimal &wronganimal);
    ~WrongAnimal();

    std::string getType() const;
    void makeSound() const;
};

#endif
