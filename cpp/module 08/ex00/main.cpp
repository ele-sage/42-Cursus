#include "easyfind.hpp"

int main()
{
    srand(time(NULL));
    const int SIZE = 1000;

    std::vector<int> vect;
    std::list<int> lst;
    std::deque<int> deq;

    int random;

    for (int i = 0; i < SIZE; i++)
    {
        random = rand() % SIZE;
        vect.push_back(random);
        lst.push_back(random);
        deq.push_back(random);
    }

    printContainer(vect, "Vector", rand() % SIZE);
    printContainer(lst, "List", rand() % SIZE);
    printContainer(deq, "Deque", rand() % SIZE);

    return 0;
}