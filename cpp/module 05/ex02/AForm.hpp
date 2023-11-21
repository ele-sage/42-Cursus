#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

using std::exception;
using std::string;
using std::cout;

class Bureaucrat;

class AForm
{
private:
    const string    _name;
    bool            _signed;
    const int       _gradeToSign;
    const int       _gradeToExecute;
    const string    _target;
    AForm();

public:
    AForm(const string &name, int gradeToSign, int gradeToExecute, const string &target);
    AForm(const AForm &form);
    AForm& operator=(const AForm &form);
    virtual ~AForm();

    string  getName() const;
    bool    getSigned() const;
    int     getGradeToSign() const;
    int     getGradeToExecute() const;
    string  getTarget() const;
    void    beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(const Bureaucrat &executor) const = 0;

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

    class NotSignedException : public exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif