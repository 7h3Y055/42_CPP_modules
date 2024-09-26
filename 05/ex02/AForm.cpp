#include "AForm.hpp"

AForm::AForm():name("default"), gradeToSign(150), isSigned(0){
}

AForm::AForm(std::string name, int gradeToSign):name(name), gradeToSign(gradeToSign), isSigned(0){
    try
    {
        if (gradeToSign < 1)
            throw AForm::GradeTooHighException();
        else if (gradeToSign > 150)
            throw AForm::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::AForm(const AForm &copy):name(copy.name), gradeToSign(copy.gradeToSign){
    *this = copy;
}


AForm &AForm::operator=(const AForm &copy){
    if (this == &copy){
        isSigned = copy.isSigned;
    }
    return *this;
}

AForm::~AForm(){
}

std::ostream &operator<<(std::ostream &out, const AForm &r){
    out << "AForm name: " << r.getName() << ", Grade To Sign: " << r.getGradeToSign() << ", Is Sign: " << r.getIsSigned() ;
    return out;
}


const char *AForm::GradeTooHighException::what() const throw(){
    return "[!] Grade Too High Exception";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "[!] Grade Too Low Exception";
}


std::string AForm::getName() const{
    return name;
}
int AForm::getGradeToSign() const{
    return gradeToSign;
}
bool    AForm::getIsSigned() const{
    return isSigned;
}

int AForm::beSigned(const Bureaucrat &b){
    try
    {
        if (this->gradeToSign >= b.getGrade()){
            this->isSigned = 1;
        }else{
            throw AForm::GradeTooLowException();
        }
        return 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}


