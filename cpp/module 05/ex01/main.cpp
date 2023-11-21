#include "Form.hpp"

int main()
{
    int bGrade = 1;
    int fGrade = 1;
    
    try
    {
        Bureaucrat b("Bureaucrat A", bGrade);
        Form f("Form A", fGrade, fGrade);
        b.signForm(f);
    }
    catch (std::exception &e)
    {
        cout << endl << e.what() << endl << endl;
    }

    fGrade = -1;
    try
    {
        Bureaucrat b("Bureaucrat A", bGrade);
        Form f("Form A", fGrade, fGrade);
        b.signForm(f);
    }
    catch (std::exception &e)
    {
        cout << endl << e.what() << endl << endl;
    }

    bGrade = 150;
    fGrade = 149;
    try
    {
        Bureaucrat b("Bureaucrat A", bGrade);
        Form f("Form A", fGrade, fGrade);
        b.signForm(f);
    }
    catch (std::exception &e)
    {
        cout << endl << e.what() << endl << endl;
    }
    return (0);
}
