#include "Bureaucrat.hpp"

int main()
{
    // int grade = 1;

    // try
    // {
    //     Bureaucrat a("Bureaucrat A", grade);
    //     a.incrementGrade();
    //     cout << a << endl;
    // }
    // catch (std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    // grade = 150;
    // try
    // {
    //     Bureaucrat a("Bureaucrat A", grade);
    //     a.decrementGrade();
    //     cout << a << endl;
    // }
    // catch (std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    int grade = 0;
    do
    {
        try
        {
            Bureaucrat a("Bureaucrat A", grade);
            cout << a << endl;
        }
        catch (std::exception &e)
        {
            cout << e.what() << endl;
        }
        grade++;
    } while (grade <= 151);
    return (0);
}
