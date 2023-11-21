#include "Base.hpp"

int     main(void)
{
    srand(time(NULL));

    cout << endl;

    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    cout << "--------------------------------" << endl;

    identify(a);
    identify(b);
    identify(c);
    identify(d);

    cout << "--------------------------------" << endl;

    identify(*a);
    identify(*b);
    identify(*c);
    identify(*d);

    cout << endl;

    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}