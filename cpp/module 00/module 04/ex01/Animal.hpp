#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

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
    virtual void makeSound() const;
};

#endif
