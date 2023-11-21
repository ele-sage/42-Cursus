#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern& Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern()
{

}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

static AForm* makeShrubberyCreationForm(const string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomyRequestForm(const string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makePresidentialPardonForm(const string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const string &name, const string &target)
{
	typedef struct s_form
	{
		string name;
		AForm* (*func)(const string &target);
	} t_form;

	t_form forms[] = {
		{"shrubbery creation", makeShrubberyCreationForm},
		{"robotomy request", makeRobotomyRequestForm},
		{"presidential pardon", makePresidentialPardonForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			cout << "Intern creates " << name << endl;
			return (forms[i].func(target));
		}
	}
	throw FormNotFoundException();
}