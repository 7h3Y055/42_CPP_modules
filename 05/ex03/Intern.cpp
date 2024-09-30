#include "Intern.hpp"

Intern::Intern(){

}

Intern::Intern(Intern const &other){
    (void)other;
}

Intern &Intern::operator=(Intern const &other){
    (void)other;
    return *this;
}

Intern::~Intern(){
}


Form *Intern::makeForm(std::string name, std::string target){
    int i;

    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (i = 0;formNames[i] != name && i < 3; i++);

    switch (i)
    {
        case 0:
            return new ShrubberyCreationForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Form not found" << std::endl;
            return NULL;
    }
}