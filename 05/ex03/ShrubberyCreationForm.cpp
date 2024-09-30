#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form(copy){
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}


int ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    try
    {
        if (this->getIsSigned() && executor.getGrade() <= 137)
        {
            std::ofstream file((this->target + "_shrubbery").c_str());
            file << "       _-_" << std::endl;
            file << "    /~~   ~~\\" << std::endl;
            file << " /~~         ~~\\" << std::endl;
            file << "{               }" << std::endl;
            file << " \\  _-     -_  /" << std::endl;
            file << "   ~  \\\\ //  ~" << std::endl;
            file << "_- -   | | _- _" << std::endl;
            file << "  _ -  | |   -_" << std::endl;
            file << "      // \\\\" << std::endl;
            file.close();
            return 0;
        }
        else
        {
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}


