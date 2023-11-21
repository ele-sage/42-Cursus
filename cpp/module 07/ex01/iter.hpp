#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void iter(T *arr, size_t len, void (*f)(T const &))
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void print(T const &x)
{
    cout << x << " ";
}

#endif