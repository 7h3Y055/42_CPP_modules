#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


// shrubbery creation
// robotomy request
// presidential pardon


int main() {
    Intern intern;

    {
        Form *x = intern.makeForm("robotomy request", "home");
        if (x){
            Bureaucrat b("b", 1);
            b.signForm(*x);
            b.executeForm(*x);
            delete x;
        }
    }
    
    return 0;
}
