#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): sign(145), exec(137), target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): sign(145), exec(137), target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy){
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
    if (this != &copy){
        sign = copy.sign;
        exec = copy.exec;
        target = copy.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    try
    {
        if (executor.getGrade() <= 145 && )//add exec
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


