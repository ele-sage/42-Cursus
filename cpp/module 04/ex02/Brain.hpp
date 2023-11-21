#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

using std::cout;
using std::endl;

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain(const Brain &brain);
    Brain& operator=(const Brain &brain);
    ~Brain();
};

#endif