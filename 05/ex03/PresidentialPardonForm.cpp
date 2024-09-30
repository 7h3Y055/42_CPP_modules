#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), target("default"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form(copy){
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}


int PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    try
    {
        if (this->getIsSigned() && executor.getGrade() <= 5){
            std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
        }
        else{
            throw Form::GradeTooLowException();
        }
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}


