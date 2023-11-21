#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ctime>

#define MAX_VALID_YR 9999
#define MIN_VALID_YR 0

using std::cout;
using std::endl;
using std::string;
using std::exception;

class Date
{
private:
    unsigned int _year;
    unsigned int _month;
    unsigned int _day;
    string       _dateFormated;

    Date();
public:
    Date(const string &date);
    Date(const Date &copy);
    ~Date();
    Date &operator=(const Date &copy);
    bool operator==(const Date &copy) const;
    bool operator!=(const Date &copy) const;
    bool operator<(const Date &copy) const;
    bool operator>(const Date &copy) const;

    string getDate() const;

    class InvalidDate : public exception
    {
    private:
        string _dateFormated;
        char* _errorMessage;
    public:
        InvalidDate(const string &date);
        virtual ~InvalidDate() throw();
        virtual const char* what() const throw();
    };
};

inline std::ostream& operator<<(std::ostream &out, const Date &date)
{
    out << date.getDate();
    return out;
}


#endif