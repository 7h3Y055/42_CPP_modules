#include "Bureaucrat.hpp"
#include "AForm.hpp"


std::string Bureaucrat::getName() const{
    return name;
}

int         Bureaucrat::getGrade() const{
    return grade;
}

void        Bureaucrat::increment(){
    try{
        if (grade == 1){
            throw Bureaucrat::GradeTooHighException();
        }
        grade--;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void        Bureaucrat::decrement(){
    try{
        if (grade == 150){
            throw Bureaucrat::GradeTooHighException();
        }
        grade++;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
char const *Bureaucrat::GradeTooHighException::what() const throw(){
    return "[!] Grade Too High Exception";
}

char const *Bureaucrat::GradeTooLowException::what() const throw(){
    return "[!] Grade Too Low Exception";
}


Bureaucrat::Bureaucrat(): name("Default"), grade(150), execute(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade, int execute):name(name), execute(execute){
    try{
        if (grade < 1){
            throw Bureaucrat::GradeTooHighException();
        }
        else if (grade > 150){
            throw Bureaucrat::GradeTooLowException();
        }
        this->grade = grade;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
    if (this != &copy)
    {
        this->name = copy.name;
        this->grade = copy.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){
}

void    Bureaucrat::signAForm(AForm &f){
    if (f.beSigned(*this)){
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    else{
        std::cout << this->getName() << " couldn’t sign " << f.getName() << " because " << "Grade too low" << std::endl;
    }
}

int Bureaucrat::getExecute() const{
    return this->execute;
}

