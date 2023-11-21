#include "DoubleScalar.hpp"

static bool inRange(string value)
{
    try
    {
        stod(value);
    }
    catch (const std::exception& e)
    {
        return false;
    }
    return true;
}

DoubleScalar::DoubleScalar(string value) : Literal(value, "double"), _doubleValue(0)
{
    if (isFloat(value) && inRange(value))
        _doubleValue = stod(value);
    else if (value.length() == 1 && isalpha(value[0]))
        _doubleValue = static_cast<double>(value[0]);
    else
        setException();
}

DoubleScalar::DoubleScalar(const DoubleScalar& copy) : Literal(copy)
{
    _doubleValue = copy._doubleValue;
}

DoubleScalar::~DoubleScalar()
{

}

void DoubleScalar::print() const
{
    cout << _type << ": ";
    if (_exception.empty())
    {
        cout << _doubleValue;
        if (static_cast<int>(_doubleValue) == _doubleValue)
            cout << ".0";
    }
    else
        cout << _exception;
    cout << endl;
}