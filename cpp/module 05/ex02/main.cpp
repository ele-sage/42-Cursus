#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    try
    {
        Bureaucrat bureaucrat("Emile", 2); // error with 200
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        cout << "\n\n--------------- Form 1 ---------------" << endl;
        bureaucrat.executeForm(form1);
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        cout << "\n\n--------------- Form 2 ---------------" << endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        cout << "\n\n--------------- Form 3  ---------------" << endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return EXIT_SUCCESS;
}