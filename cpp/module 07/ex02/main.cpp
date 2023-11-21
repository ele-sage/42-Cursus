#include "Array.hpp"

int main() {

    Array<int> emptyArray;
    Array<int> intArray(5);

    cout << endl << "Empty Array Size: " << emptyArray.getSize() << endl;
    cout << endl << "Int Array Size: " << intArray.getSize() << endl << endl;

    intArray[0] = 42;
    intArray[1] = 10;

    intArray.print();

    try
    {
        intArray[10] = 99;
    }
    catch (const std::exception& e)
    {
        std::cerr << endl << "Exception: " << e.what() << endl;
    }
    

    Array<int> copyArray(intArray);
    Array<int> anotherArray;
    anotherArray = intArray;

    cout << endl << "Copy Array Size: " << copyArray.getSize() << endl;
    cout << endl << "Another Array Size: " << anotherArray.getSize() << endl;

    copyArray[copyArray.getSize() - 1] = 21;
    anotherArray[anotherArray.getSize() - 1] = 84;
    
    
    cout << endl << "Copy Array : ";
    copyArray.print();
    cout << endl << "Another Array : ";
    anotherArray.print();
    cout << endl << "Int Array : ";
    intArray.print();
    cout << endl;
    return 0;
}