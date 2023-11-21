#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using std::cout;
using std::endl;

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &animal);
    Animal& operator=(const Animal &animal);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif