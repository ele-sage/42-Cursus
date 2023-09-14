#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

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
