#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
public:
    Intern();
    Intern(const Intern &intern);
    Intern& operator=(const Intern &intern);
    ~Intern();

    AForm* makeForm(const string &name, const string &target);

    class FormNotFoundException : public exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif