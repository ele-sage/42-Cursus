#include "iter.hpp"

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    string strArr[] = {"one", "two", "three", "four", "five"};

    cout << "intArr: ";
    iter(intArr, 5, print);
    cout << endl;

    cout << "charArr: ";
    iter(charArr, 5, print);
    cout << endl;

    cout << "strArr: ";
    iter(strArr, 5, print);
    cout << endl;

    return 0;
}