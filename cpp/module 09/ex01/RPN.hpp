#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <sstream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::exception;
using std::stringstream;

class RPN
{
private:
    stack<double> _stack;
    string _line;
    RPN();
public:
    RPN(const string &line);
    RPN(const RPN &copy);
    ~RPN();
    RPN &operator=(const RPN &copy);

    void calculate();
    void printStack() const;

    class InvalidValue : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: invalid value."; }
    };

    class DivisionByZero : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: division by zero."; }
    };

    class InvalidExpression : public exception
    {
    public:
        virtual const char* what() const throw() { return "Error: invalid expression."; }
    };
};

#endif