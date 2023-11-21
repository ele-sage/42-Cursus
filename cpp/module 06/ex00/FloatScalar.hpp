#ifndef FLOATSCALAR_HPP
#define FLOATSCALAR_HPP

#include "Literal.hpp"

class FloatScalar : public Literal
{
private:
    float _floatValue;
    FloatScalar();

public:
    FloatScalar(string value);
    FloatScalar(const FloatScalar& copy);
    ~FloatScalar();

    void print() const;
};

#endif