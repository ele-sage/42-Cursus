#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Literal
{
private:
    Literal();

protected:
    const string    _value;
    const string    _type;
    string          _exception;

public:
    Literal(string value, string type);
    Literal(const Literal& copy);
    virtual ~Literal();

    string  getValue() const;
    string  getType() const;
    void    setException();
    bool    isFloat(string value) const;

    virtual void print() const = 0;
};

#endif