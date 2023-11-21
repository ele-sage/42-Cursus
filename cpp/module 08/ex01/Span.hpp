#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using std::exception;
using std::vector;
using std::cout;
using std::endl;

class Span
{
private:
    unsigned int _len;
    unsigned int _index;
    vector<int> _array;
    
public:
    Span();
    Span(unsigned int len);
    Span(Span const &copy);
    ~Span();
    Span &operator=(Span const &copy);

    void addNumber(int number);
    void addNumber(vector<int>::const_iterator start, vector<int>::const_iterator end);
    int shortestSpan();
    int longestSpan();

    unsigned int getSize() const;
    unsigned int getIndex() const;
    unsigned int getNumAt(unsigned int index) const;
    vector<int> getArray() const;

    class ArrayFull : public exception
    {
    public:
        virtual const char* what() const throw() {return "The array is already full.";}
    };

    class IndexExceed : public exception
    {
    public:
        virtual const char* what() const throw() {return "The index exceed the size of the array.";}
    };

    class SpanMinRequierement : public exception
    {
    public:
        virtual const char* what() const throw() {return "In order to get the span, your array need to contain at least 2 elements.";}
    };

};

#endif