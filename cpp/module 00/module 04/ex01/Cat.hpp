#ifndef CAT_H
#define CAT_H

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
    
public:
    Cat();
    Cat(const Cat &cat);
    Cat& operator=(const Cat &cat);
    ~Cat();

    void makeSound() const;
};

#endif
