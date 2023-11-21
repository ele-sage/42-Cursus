#ifndef DOUBLESCALAR_HPP
#define DOUBLESCALAR_HPP

#include "Literal.hpp"

class DoubleScalar : public Literal
{
private:
    double _doubleValue;
    DoubleScalar();

public:
    DoubleScalar(string value);
    DoubleScalar(const DoubleScalar& copy);
    ~DoubleScalar();

    void print() const;
};



#endif