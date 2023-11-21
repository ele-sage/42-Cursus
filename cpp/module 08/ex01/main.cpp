#include "Span.hpp"

const int SIZE = 100;

int randomNum() 
{ 
    return (rand() % SIZE);
} 

int main()
{
    srand(time(NULL));
    Span sp1(SIZE);
    Span sp2(sp1);
    vector<int> vec(SIZE);

    std::generate(vec.begin(), vec.end(), randomNum);

    cout << endl << "Numbers : ";
    for (int i = 0; i < SIZE; i++)
    {
        int random = rand() % SIZE;
        cout << random << " ";
        sp2.addNumber(random);
    }

    try
    {
        cout << endl << endl << "Shortest Span : " << sp2.shortestSpan() << endl;
        cout << endl << "Longest Span : " << sp2.longestSpan() << endl;
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << endl << sp2.getSize() << endl;

    try
    {
        sp2.addNumber(rand() % 1000);
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << endl << sp2.getSize() << endl;

    sp1.addNumber(30);
    try
    {
        sp1.addNumber(vec.begin(), vec.end());
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        for(unsigned int i = 0; i < sp1.getSize(); i++)
            cout << sp1.getNumAt(i) << " ";
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}