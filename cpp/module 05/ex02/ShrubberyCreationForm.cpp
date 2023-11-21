#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    if (this != &form)
        AForm::operator=(form);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::ofstream file;
    file.open(this->getTarget() + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "       | |     " << std::endl;
    file << "       | |     " << std::endl;
    file << "      // \\\\" << std::endl;
    file << std::endl;
}