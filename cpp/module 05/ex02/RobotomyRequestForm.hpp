#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const string &target);
    RobotomyRequestForm(const RobotomyRequestForm &form);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &form);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &executor) const;
};

#endif