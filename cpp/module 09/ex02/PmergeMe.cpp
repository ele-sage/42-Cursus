#include "PmergeMe.hpp"
#include "mergeSort.hpp"

void PmergeMe::run()
{
    stringstream ss;

    vector<u_int>::const_iterator it = _vector.begin();
    for (;(it < _vector.begin() + 5) && it < _vector.end(); it ++)
        ss << *it << " ";
    if (_vector.size() > 5)
        ss << "[...]";
    else if (_vector.size() == 5)
        ss << *it;
    cout << "Before: " << ss.str() << endl;
    ss.str(std::string());

    high_resolution_clock::time_point start, end;

    start = high_resolution_clock::now();
    mergeSort(_vector);
    end = high_resolution_clock::now();
    _deltaVector = duration_cast<duration<double> >(end - start);

    start = high_resolution_clock::now();
    mergeSort(_deque);
    end = high_resolution_clock::now();
    _deltaDeque = duration_cast<duration<double> >(end - start);

    it = _vector.begin();
    for (;(it < _vector.begin() + 5) && it < _vector.end(); it ++)
        ss << *it << " ";
    if (_vector.size() > 5)
        ss << "[...]";
    else if (_vector.size() == 5)
        ss << *it;
    cout << "After:  " << ss.str() << endl;
    cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _deltaVector.count() << " s" << endl;
    cout << "Time to process a range of " << _deque.size() << " elements with std::vector : " << _deltaDeque.count() << " s" << endl;
}

void PmergeMe::parseArgs(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] < '0' || argv[i][0] > '9')
            throw InvalidValue();
        stringstream ss(argv[i]);
        u_int value;
        ss >> std::noskipws >> value;
        if (!(ss.eof() && !ss.fail()))
            throw InvalidValue();
        _vector.push_back(value);
        _deque.push_back(value);
    }
}

PmergeMe::PmergeMe(int argc, char* argv[])
{
    if (argc < 2)
        throw InvalidUsage();
    parseArgs(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        _vector = copy._vector;
        _deque = copy._deque;
        _deltaDeque = copy._deltaDeque;
        _deltaVector = copy._deltaVector;
    }
    return *this;
}
