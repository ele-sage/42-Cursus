#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();

public:
    PresidentialPardonForm(const string &target);
    PresidentialPardonForm(const PresidentialPardonForm &form);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &form);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &bureaucrat) const;

};

#endif