#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
		AForm::operator=(form);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	cout << "* drilling noises *" << endl;
	if (rand() % 2)
		cout << getTarget() << " has been robotomized successfully" << endl;
	else
		cout << getTarget() << " robotomization failed" << endl;
}