#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &form);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;
};

#endif