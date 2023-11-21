#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

using std::exception;
using std::string;
using std::cout;

class Bureaucrat;

class Form
{
private:
    const string    _name;
    bool            _signed;
    const int       _gradeToSign;
    const int       _gradeToExecute;
    Form();

public:
    Form(const string &name, int gradeToSign, int gradeToExecute);
    ~Form();

    string  getName() const;
    bool    getSigned() const;
    int     getGradeToSign() const;
    int     getGradeToExecute() const;
    void    beSigned(const Bureaucrat &bureaucrat);

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

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif