#ifndef DATA_HPP
#define DATA_HPP

#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Data
{
    string      serialize;
    uintptr_t   raw;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif