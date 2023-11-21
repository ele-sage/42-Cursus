#include "MutantStack.hpp"

int main()
{
    cout << "-------- MutantStack --------" << endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    cout << mstack.top() << endl;

    mstack.pop();
    cout << mstack.size() << endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator mStack_begin = mstack.begin();
    MutantStack<int>::iterator mStack_end = mstack.end();
    ++mStack_begin;
    --mStack_begin;

    while (mStack_begin != mStack_end)
    {
        cout << *mStack_begin << endl;
        ++mStack_begin;
    }
    std::stack<int> realStack(mstack);

    cout << endl << "--------- std::stack ---------" << endl;

    while (!realStack.empty())
    {
        cout << realStack.top() << endl;
        realStack.pop();
    }


    cout << endl << "----------- vector -----------" << endl;

    std::vector< int > vec;

    vec.push_back(5);
    vec.push_back(17);

    cout << vec.back() << endl;

    vec.pop_back();
    cout << vec.size() << endl;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    //[...]
    vec.push_back(0);

    std::vector<int>::iterator vec_begin = vec.begin();
    std::vector<int>::iterator vec_end = vec.end();
    ++mStack_begin;
    --mStack_begin;
    while (vec_begin != vec_end)
    {
        cout << *vec_begin << endl;
        ++vec_begin;
    }
    std::vector<int> l(vec);

    return 0;
}