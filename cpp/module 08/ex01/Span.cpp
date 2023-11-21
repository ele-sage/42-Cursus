#include "Span.hpp"

Span::Span() : _len(0), _index(0)
{

}

Span::Span(unsigned int len) : _len(len), _index(0)
{
    _array.reserve(len);
}

Span::Span(Span const &copy)
{
    if (this != &copy)
        *this = copy;
}

Span::~Span()
{

}

Span& Span::operator=(Span const &copy)
{
    if (this != &copy)
    {
        _len = copy._len;
        _index = copy._index;
        _array = copy._array;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (_index >= _len)
        throw ArrayFull();
    else
    {
        _index++;
        _array.push_back(number);
    }
}

void Span::addNumber(vector<int>::const_iterator start, vector<int>::const_iterator end)
{
    if (_index >= _len)
        throw ArrayFull();
    else
    {
        _index = _len;
        _array.insert(_array.end(), start, end);
    }
}

int Span::shortestSpan()
{
    if (_index < 2)
        throw SpanMinRequierement();

    int span = abs(_array[1] - _array[0]);
    vector<int>::iterator ptr = _array.begin();

    for (; ptr < _array.end() - 1; ptr++)
        for (vector<int>::iterator ptr_end = _array.end() - 1; ptr < ptr_end; ptr_end--)
            if (span > abs(*ptr_end - *ptr))
                span = abs(*ptr_end - *ptr);

    return span;
}

int Span::longestSpan()
{
    if (_index < 2)
        throw SpanMinRequierement();

    int span = abs(_array[1] - _array[0]);
    vector<int>::iterator ptr = _array.begin();
    
    for (; ptr < _array.end() - 1; ptr++)
        for (vector<int>::iterator ptr_end = _array.end() - 1; ptr < ptr_end; ptr_end--)
            if (span < abs(*ptr_end - *ptr))
                span = abs(*ptr_end - *ptr);

    return span;
}

unsigned int Span::getSize() const
{
    return (_len);
}

unsigned int Span::getIndex() const
{
    return (_index);
}

unsigned int Span::getNumAt(unsigned int index) const
{
    if (index >= _index)
        throw IndexExceed();
    else
        return (_array.at(index));
}

vector<int> Span::getArray() const
{
    return (_array);
}