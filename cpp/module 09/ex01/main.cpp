#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw RPN::InvalidExpression();
        RPN rpn(argv[1]);
        rpn.calculate();
        rpn.printStack();
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return (0);
}