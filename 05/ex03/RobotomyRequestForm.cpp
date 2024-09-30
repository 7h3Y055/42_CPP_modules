#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), target("default"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form(copy){
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}


int RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    try
    {
        if (this->getIsSigned() && executor.getGrade() <= 45)
        {
            if (std::time(0) % 2){
                std::cout << "[+] " << target << " has been robotomized" << std::endl;
            }else{
                std::cout << "[-] " << target << " has been failed" << std::endl;
                throw Form::GradeTooLowException();
            }
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


