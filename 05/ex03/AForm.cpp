#include "AForm.hpp"

Form::Form():name("default"), gradeToSign(150), gradeToExec(150), isSigned(0){
}

Form::Form(std::string name, int gradeToSign, int gradeToExec):name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(0){
    try
    {
        if (gradeToSign < 1 || gradeToExec < 1)
            throw Form::GradeTooHighException();
        else if (gradeToSign > 150 || gradeToExec > 150)
            throw Form::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::Form(const Form &copy):name(copy.name), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec), isSigned(copy.isSigned){
}


Form &Form::operator=(const Form &copy){
    if (this == &copy){
        isSigned = copy.isSigned;
    }
    return *this;
}

Form::~Form(){
}

std::ostream &operator<<(std::ostream &out, const Form &r){
    out << "Form name: " << r.getName() << ", Grade To Sign: " << r.getGradeToSign() <<", Grade To Sign: " << r.getGradeToExec() << ", Is Sign: " << r.getIsSigned() ;
    return out;
}


const char *Form::GradeTooHighException::what() const throw(){
    return "[!] Grade Too High Exception";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "[!] Grade Too Low Exception";
}


std::string Form::getName() const{
    return name;
}

int Form::getGradeToSign() const{
    return gradeToSign;
}

int Form::getGradeToExec() const{
    return gradeToExec;
}

bool    Form::getIsSigned() const{
    return isSigned;
}

int Form::beSigned(const Bureaucrat &b){
    try
    {
        if (this->gradeToSign >= b.getGrade()){
            this->isSigned = 1;
        }else{
            throw Form::GradeTooLowException();
        }
        return 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}


