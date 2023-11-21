#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include "Date.hpp"
#include <fstream>
#include <sstream>
#include <regex>
#include <map>

using std::map;
using std::vector;

class Bitcoin
{
private:
    map<Date *, float> _data;

    Bitcoin();

public:
    Bitcoin(const string &fileName);
    ~Bitcoin();
    float operator[](const Date &date) const;
    float operator[](const string &date) const;

    void printValues(const string &fileName) const;
    
    const map<Date *, float> &getData() const { return _data; }

    class InvalidFile : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: could not open file."; }
    };

    class InvalidDate : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: invalid date."; }
    };

    class InvalidValue : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: not a positive number."; }
    };

    class TooLarge : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: too large a number."; }
    };
};

inline std::ostream& operator<<(std::ostream &out, const Bitcoin &btc)
{
    const map<Date *, float>& data = btc.getData();
    for (map<Date *, float>::const_iterator it = data.begin(); it != data.end(); it++)
    {
        out << *(it->first) << " | " << it->second << std::endl;
    }
    return (out);
}

#endif