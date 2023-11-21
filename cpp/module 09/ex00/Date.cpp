#include "Date.hpp"

static bool isLeap(int year) 
{ 
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
}

static bool isStringValid(const string &date)
{
    string::const_iterator it = date.begin();
    int sep = 0;

    if (date.size() > 10)
        return (false);
    while (it != date.end())
    {
        if (!std::isdigit(*it))
        {
            if (*it == '-')
                sep++;
            else
                return (false);
        }
        ++it;
    }
    if (date[date.size() - 1] == '-' || sep != 2)
        return (false);
    return (true);
}

static bool isValidDate(const string &date)
{
    int y, m, d;

    if (!isStringValid(date))
        return (false);
    y = stoi(date.substr(0, date.find_first_of('-')));
    m = stoi(date.substr(date.find_first_of('-') + 1, date.find_last_of('-')));
    d = stoi(date.substr(date.find_last_of('-') + 1, date.size() - 1));

    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2) 
    { 
        if (isLeap(y)) 
            return (d <= 29); 
        else
            return (d <= 28); 
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) 
        return (d <= 30);
    return true;
}

Date::Date(const string &date) : _year(stoi(date.substr(0, date.find_first_of('-')))),
                        _month(stoi(date.substr(date.find_first_of('-') + 1, date.find_last_of('-')))),
                        _day(stoi(date.substr(date.find_last_of('-') + 1, date.size() - 1))),
                        _dateFormated(date)
{
    if (!isValidDate(date))
        throw InvalidDate(date);
}

Date::Date(const Date &copy)
{
    *this = copy;
}

Date::~Date()
{

}

Date &Date::operator=(const Date &copy)
{
    if (this != &copy)
    {
        _year = copy._year;
        _month = copy._month;
        _day = copy._day;
        _dateFormated = copy._dateFormated;
    }
    return (*this);
}

bool Date::operator==(const Date &copy) const
{
    return (_dateFormated.compare(copy._dateFormated) == 0);
}

bool Date::operator!=(const Date &copy) const
{
    return (_dateFormated.compare(copy._dateFormated) != 0);
}

bool Date::operator<(const Date &copy) const
{
    if (_year < copy._year)
        return (true);
    else if (_year == copy._year)
    {
        if (_month < copy._month)
            return (true);
        else if (_month == copy._month)
            if (_day < copy._day)
                return (true);
    }
    return (false);
}

bool Date::operator>(const Date &copy) const
{
    if (_year > copy._year)
        return (true);
    else if (_year == copy._year)
    {
        if (_month > copy._month)
            return (true);
        else if (_month == copy._month)
            if (_day > copy._day)
                return (true);
    }
    return (false);
}

string Date::getDate() const
{
    return (_dateFormated);
}

Date::InvalidDate::InvalidDate(const string &date) : _dateFormated(date)
{
    _errorMessage = new char[100];
    strcpy(_errorMessage, "Error: bad input => ");
    strcat(_errorMessage, date.c_str());
}

Date::InvalidDate::~InvalidDate() throw()
{
    delete [] _errorMessage;
}

const char* Date::InvalidDate::what() const throw()
{
    return (_errorMessage);
}