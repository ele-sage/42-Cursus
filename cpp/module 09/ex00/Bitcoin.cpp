#include "Bitcoin.hpp"

static bool isValidFile(const string &file)
{
    if (file.find(".csv") == string::npos)
        return (false);
    return (true);
}

static bool inRange(float value, float min, float max)
{
    if (value < min)
        throw Bitcoin::InvalidValue();
    else if (value > max)
        throw Bitcoin::TooLarge();
    return (true);
}

static bool isFloat(const string &str) {
    std::istringstream ss(str);
    float f;
    ss >> std::noskipws >> f;
    if (!(ss.eof() && !ss.fail()))
        throw Bitcoin::InvalidValue();
    return (true);
}

Bitcoin::Bitcoin(const string &file)
{
    if (!isValidFile(file))
        throw Bitcoin::InvalidFile();
    std::ifstream ifs(file);
    if (!ifs.is_open())
        throw Bitcoin::InvalidFile();
    string line;
    int i = 0;
    while (getline(ifs, line))
    {
        if (line.compare("date,exchange_rate") == 0)
            continue;
        size_t pos = line.find(',');
        string date = line.substr(0, pos);
        string value = line.substr(pos + 1);
        i++;
        try
        {
            isFloat(value);
            Date *d = new Date(date);
            _data.insert(std::pair<Date *, float>(d, std::stof(value)));
        }
        catch(const std::exception& e)
        {
            std::cerr << "Line " << i << ": " << line << " | " << e.what() << endl;
            continue;
        }
    }
    ifs.close();
}

Bitcoin::~Bitcoin()
{
    for (map<Date *, float>::iterator it = _data.begin(); it != _data.end(); it++)
        delete it->first;
}

float Bitcoin::operator[](const Date &date) const
{
    map<Date *, float>::const_reverse_iterator it = _data.rbegin();
    while (it != _data.rend())
    {
        if (*(it->first) == date)
            return (it->second);
        else if (*(it->first) < date)
            return (it->second);
        it++;
    }
    throw Bitcoin::InvalidDate();
}

float Bitcoin::operator[](const string &date) const
{
    Date d(date);
    return ((*this)[d]);
}

void Bitcoin::printValues(const string &fileName) const
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
        throw Bitcoin::InvalidFile();
    string line;
    while (getline(ifs, line))
    {
        if (line.compare("date | value") == 0)
            continue;
        size_t pos = line.find(" | ");
        string date = line.substr(0, pos);
        string value = line.substr(pos + 3);
        try
        {
            Date d(date);
            isFloat(value);
            float q = std::stof(value);
            inRange(q, 0, 1000);
            cout << date << " => " << std::stof(value) <<  " = " << (q * (*this)[d]) << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
    ifs.close();
}