#ifndef INTSCALAR_HPP
#define INTSCALAR_HPP

#include "Literal.hpp"

class IntScalar : public Literal
{
private:
    int _intValue;
    IntScalar();

public:
    IntScalar(string value);
    IntScalar(const IntScalar& copy);
    ~IntScalar();

    void print() const;
};

#endif