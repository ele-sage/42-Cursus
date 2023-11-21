#include "RPN.hpp"

RPN::RPN(const string &line) : _line(line)
{
    if (line.empty() || line.find_first_not_of("0123456789.+-*/ ") != string::npos)
        throw RPN::InvalidExpression();
}

RPN::RPN(const RPN &copy) : _line(copy._line)
{
    *this = copy;
}

RPN::~RPN()
{

}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        _stack = copy._stack;
    return (*this);
}

void RPN::calculate()
{
    stringstream ss(_line);
    string token;
    double a, b;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw InvalidExpression();
            a = _stack.top();
            _stack.pop();
            b = _stack.top();
            _stack.pop();
            if (token == "+")
                _stack.push(b + a);
            else if (token == "-")
                _stack.push(b - a);
            else if (token == "*")
                _stack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                    throw DivisionByZero();
                _stack.push(b / a);
            }
        }
        else
        {
            stringstream ss(token);
            double value;
            if (!(ss >> value))
                throw InvalidValue();
            _stack.push(value);
        }
    }
    if (_stack.size() == 0)
        throw InvalidExpression();
}

void RPN::printStack() const
{
    stack<double> tmp = _stack;
    while (!tmp.empty())
    {
        cout << " " << tmp.top() << endl;
        tmp.pop();
    }
    cout << "---" << endl << "Stack" << endl;
    cout << "The result is: " << _stack.top() << endl;
}