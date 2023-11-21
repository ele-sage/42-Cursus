#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <sstream>
#include <chrono>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::exception;
using std::stringstream;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;


typedef unsigned int u_int;

class PmergeMe
{
private:
        vector<u_int>       _vector;
        deque<u_int>        _deque;
        duration<double>    _deltaVector;
        duration<double>    _deltaDeque;
        PmergeMe();

        void parseArgs(int argc, char* argv[]);

    public:
        PmergeMe(int argc, char* argv[]);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &copy);

    void run();

    class InvalidValue : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: invalid value."; }
    };

    class InvalidUsage : public exception
    {
    public:
        virtual const char* what() const throw() { return "Usage: ./PmergeMe <int> <int> <int> ..."; }
    };
};

#endif