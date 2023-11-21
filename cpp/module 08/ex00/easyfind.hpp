#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>

using std::cout;
using std::endl;


template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::exception();
    return it;
}

template <typename T>
void    printContainer(T &container, std::string name, int toFind)
{
    typename T::iterator it = container.begin();

    cout << endl << name << ": " << endl;
    while (it != container.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    try
    {
        easyfind(container, toFind);
        cout << "Value: " << toFind << " found" << endl;
    }
    catch (std::exception &e)
    {
        cout << "Value: " << toFind << " not found" << endl;
    }
}

#endif