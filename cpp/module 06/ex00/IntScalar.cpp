#include "IntScalar.hpp"

static bool inRange(string value)
{
    try
    {
        stoi(value);
    }
    catch (const std::exception& e)
    {
        return false;
    }
    return true;
}

IntScalar::IntScalar(string value) : Literal(value, "int"), _intValue(0)
{
    if (isFloat(value) && inRange(value))
        _intValue = stoi(value);
    else if (value.length() == 1 && isalpha(value[0]))
        _intValue = static_cast<int>(value[0]);
    else
        setException();
}

IntScalar::IntScalar(const IntScalar& copy) : Literal(copy)
{
    _intValue = copy._intValue;
}

IntScalar::~IntScalar()
{

}

void IntScalar::print() const
{
    cout << _type << ": ";
    if (_exception.empty())
        cout << _intValue;
    else
        cout << _exception;
    cout << endl;
}