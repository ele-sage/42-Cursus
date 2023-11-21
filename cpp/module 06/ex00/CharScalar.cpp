#include "CharScalar.hpp"

CharScalar::CharScalar(string value) : Literal(value, "char"), _charValue(0)
{
    if (value.length() == 1 && isprint(value[0]))
        _charValue = static_cast<char>(value[0]);
    else
    {
        try
        {
            int number = stoi(value);

            if (number >= 32 && number <= 126)
                _charValue = static_cast<char>(number);
            else if (number >= 0 && number <= 127)
                _exception = "Non displayable";
            else
                setException();
        }
        catch (const std::exception& e)
        {
            setException();
        }
    }
}

CharScalar::CharScalar(const CharScalar& copy) : Literal(copy)
{
    _charValue = copy._charValue;
}

CharScalar::~CharScalar()
{

}

void CharScalar::print() const
{
    cout << _type << ": ";
    if (_exception.empty())
        cout << "'" << _charValue << "'";
    else
        cout << _exception;
    cout << endl;
}