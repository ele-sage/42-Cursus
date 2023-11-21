#include "Base.hpp"

Base::~Base() {}

Base*   generate(void)
{
    char    base[3] = {'A', 'B', 'C'};
    Base*   basePtr = NULL;
    int     random = rand() % 3;

    if (random == 0)
        basePtr = new A;
    else if (random == 1)
        basePtr = new B;
    else if (random == 2)
        basePtr = new C;
    cout << "Address: " << basePtr << " -> " << base[random] << endl;
    return (basePtr);
}

void    identify(Base* p)
{
    cout << "Address: " << p << " -> ";
    if (dynamic_cast<A*>(p))
        cout << "A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "C" << endl;
}

void    identify(Base& p)
{
    cout << "Address: " << &p << " -> ";

    try
    {
        if (&dynamic_cast<A&>(p))
            cout << "A" << endl;
    }
    catch (std::bad_cast& bc)
    {
        try
        {
            if (&dynamic_cast<B&>(p))
                cout << "B" << endl;
        }
        catch (std::bad_cast& bc)
        {
            try
            {
                if (&dynamic_cast<C&>(p))
                    cout << "C" << endl;
            }
            catch (std::bad_cast& bc)
            {
                cout << "Error: " << bc.what() << endl;
            }
        }
    }
}