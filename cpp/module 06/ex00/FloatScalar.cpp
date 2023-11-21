#include "FloatScalar.hpp"
#include <cfloat>

static bool inRange(string value)
{
    try
    {
        float floatValue = stof(value);
        if (floatValue > FLT_MAX || floatValue < -FLT_MAX)
            return false;
    }
    catch (std::exception &e)
    {
        return false;
    }
    return true;
}

FloatScalar::FloatScalar(string value) : Literal(value, "float"), _floatValue(0)
{
    if (isFloat(value) && inRange(value))
        _floatValue = stof(value);
    else if (value.length() == 1 && isalpha(value[0]))
        _floatValue = static_cast<float>(value[0]);
    else
        setException();
}

FloatScalar::FloatScalar(const FloatScalar& copy) : Literal(copy)
{
    _floatValue = copy._floatValue;
}

FloatScalar::~FloatScalar()
{

}

void FloatScalar::print() const
{
    cout << _type << ": ";
    if (_exception.empty())
    {
        cout << _floatValue;
        if (static_cast<int>(_floatValue) == _floatValue)
            cout << ".0";
    }
    else
        cout << _exception;
    if (_exception.compare("impossible"))
        cout << "f";
    cout << endl;
}
