#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>

class Array
{
private:
    T               *_arr;
    unsigned int    _len;

public:
    Array();
    Array(const unsigned int len);
    Array(const Array &copy);
    Array& operator=(const Array &copy);
    ~Array();

    T& operator[](const unsigned int id);
    unsigned int getSize() const;
    void print() const;

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Index is out of bounds";}
    };
};

#include "Array.tpp"

#endif