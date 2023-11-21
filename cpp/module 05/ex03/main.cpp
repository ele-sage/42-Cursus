#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{

    Intern  someRandomIntern;
    AForm*   rrf;

    try
    {
        rrf = someRandomIntern.makeForm("wrong request", "Bender");
        delete rrf;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete rrf;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    
    
    // srand(time(NULL));
    // try
    // {
    //     Bureaucrat bureaucrat("Emile", 2); // error with 200
    //     ShrubberyCreationForm form1("Shrubbery");
    //     RobotomyRequestForm form2("Robotomy");
    //     PresidentialPardonForm form3("President");

    //     cout << "\n\n--------------- Form 1 ---------------" << endl;
    //     bureaucrat.executeForm(form1);
    //     bureaucrat.signForm(form1);
    //     bureaucrat.executeForm(form1);
    //     cout << "\n\n--------------- Form 2 ---------------" << endl;
    //     bureaucrat.signForm(form2);
    //     bureaucrat.executeForm(form2);
    //     bureaucrat.executeForm(form2);
    //     bureaucrat.executeForm(form2);
    //     bureaucrat.executeForm(form2);
    //     cout << "\n\n--------------- Form 3  ---------------" << endl;
    //     bureaucrat.signForm(form3);
    //     bureaucrat.executeForm(form3);
    // }
    // catch (exception &e)
    // {
    //     cout << e.what() << endl;
    // }
    return EXIT_SUCCESS;
}