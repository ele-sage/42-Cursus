#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain(const Brain &brain);
    Brain& operator=(const Brain &brain);
    ~Brain();

    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};

#endif