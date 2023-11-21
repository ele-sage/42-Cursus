#ifndef CHARSCALAR_HPP
#define CHARSCALAR_HPP

#include "Literal.hpp"

class CharScalar : public Literal
{
private:
    char _charValue;
    CharScalar();

public:
    CharScalar(string value);
    CharScalar(const CharScalar& copy);
    ~CharScalar();

    void print() const;
};

#endif