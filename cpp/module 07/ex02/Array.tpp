#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _len(0)
{

}

template <typename T>
Array<T>::Array(const unsigned int len) : _arr(new T[len]), _len(len)
{
    for (unsigned int i = 0; i < _len; i++)
        _arr[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(NULL), _len(0)
{
    *this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        if (_arr)
            delete[] _arr;
        _len = copy._len;
        _arr = new T[_len];
        for (unsigned int i = 0; i < _len; i++)
            _arr[i] = copy._arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
T& Array<T>::operator[](const unsigned int id)
{
    if (id >= _len)
        throw OutOfBoundsException();
    return (_arr[id]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return (_len);
}

template <typename T>
void Array<T>::print() const
{
    cout << "[";
    for (unsigned int i = 0; i < _len; i++)
    {
        cout << _arr[i];
        if (i < _len - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}