#include "AForm.hpp"

static void checkGrade(int grade)
{
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const string &name, int gradeToSign, int gradeToExecute, const string &target) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(const AForm &form) : _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute), _target(form._target)
{

}

AForm& AForm::operator=(const AForm &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

AForm::~AForm()
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}

string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

string AForm::getTarget() const
{
	return (_target);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
{
	out << "(" << form.getName() << " is ";
	if (!form.getSigned())
		out << "not ";
	out << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ")" << std::endl;
	return (out);
}
