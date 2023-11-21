#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>


using std::cout;
using std::endl;

template <typename T, class Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() {};
    ~MutantStack() {};

    MutantStack(const MutantStack& copy)
    {
        *this = copy;
    }

    MutantStack& operator=(const MutantStack& copy)
    {
        std::stack< T, Container >::operator=(copy);
        return (*this);
    }

    typedef typename Container::iterator    iterator;

    iterator begin()
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }
};

#endif