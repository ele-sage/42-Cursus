#include "Form.hpp"

static void checkGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::~Form()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed\nGrade to sign: " << form.getGradeToSign() << "\nGrade to execute: " << form.getGradeToExecute();
	return (out);
}
