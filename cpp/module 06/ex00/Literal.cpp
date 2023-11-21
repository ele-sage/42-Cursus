#include "Literal.hpp"

Literal::Literal(string value, string type) : _value(value), _type(type)
{

}

Literal::Literal(const Literal& copy) : _value(copy._value), _type(copy._type)
{

}

Literal::~Literal()
{

}

string Literal::getValue() const
{
    return (_value);
}

string Literal::getType() const
{
    return (_type);
}

void Literal::setException()
{
    if (!_value.compare("nan") || !_value.compare("-inf") || !_value.compare("+inf"))
    {
        if (!_type.compare("int") || !_type.compare("char"))
            _exception = "impossible";
        else
            _exception = _value;
    }
    else
        _exception = "impossible";
}

void Literal::print() const
{
    cout << _type << ": ";
    if (_exception.empty())
        cout << _value;
    else
        cout << _exception;
    cout << endl;
}

bool Literal::isFloat(string value) const
{
    if (value[value.length() - 1] == 'f')
        value = value.substr(0, value.length() - 1);
    int i = 0;
    if (value[i] == '+' || value[i] == '-')
        i++;
    while (value[i])
    {
        if (!isdigit(value[i]))
            break;
        i++;
    }
    if (value[i] == '.')
        i++;
    while (value[i])
    {
        if (!isdigit(value[i]))
            return (false);
        i++;
    }
    return (true);
}