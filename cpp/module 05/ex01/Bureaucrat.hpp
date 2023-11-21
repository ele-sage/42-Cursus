#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

using std::exception;
using std::string;
using std::cout;
using std::endl;

class Form;

class Bureaucrat
{
private:
    const string    _name;
    int             _grade;
    Bureaucrat();

public:
    Bureaucrat(const string &name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat& operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    string  getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();
    void    signForm(Form &form) const;

    class GradeTooHighException : public exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public exception
    {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif