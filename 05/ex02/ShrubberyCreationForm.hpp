#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    int sign;
    int execute;
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};

