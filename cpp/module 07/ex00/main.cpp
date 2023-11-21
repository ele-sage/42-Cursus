#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;
    whatever::swap(a, b);
    cout << endl << "Integers:\na = " << a << ", b = " << b << endl;
    cout << "min(a, b) = " << whatever::min(a, b) << endl;
    cout << "max(a, b) = " << whatever::max(a, b) << endl;

    string c = "chaine1";
    string d = "chaine2";
    whatever::swap(c, d);
    cout << endl << "Strings:\nc = " << c << ", d = " << d << endl;
    cout << "min(c, d) = " << whatever::min(c, d) << endl;
    cout << "max(c, d) = " << whatever::max(c, d) << endl;

    return 0;
}