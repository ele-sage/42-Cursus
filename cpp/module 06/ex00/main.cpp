#include "IntScalar.hpp"
#include "FloatScalar.hpp"
#include "DoubleScalar.hpp"
#include "CharScalar.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./convert <value>" << endl;
        return (1);
    }
    string value = argv[1];

    if (!value.compare("nanf") || !value.compare("-inff") || !value.compare("+inff"))
        value = value.substr(0, value.length() - 1);

    Literal *literal[4] = {
        new CharScalar(value),
        new IntScalar(value),
        new FloatScalar(value),
        new DoubleScalar(value)
    };
    
    for (int i = 0; i < 4; i++)
    {
        literal[i]->print();
        delete literal[i];
    }
    return (0);
}