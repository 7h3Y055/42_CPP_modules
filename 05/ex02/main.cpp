#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    std::cout << "test 1: " << std::endl;
    {
        Bureaucrat b1("b1", 1);
        ShrubberyCreationForm s1("s1");
        
        b1.signForm(s1);
        b1.executeForm(s1);
    }

    std::cout << std::endl << "test 2: " << std::endl;
    {
        Bureaucrat b2("b2", 1);
        RobotomyRequestForm r1("r1");
        
        b2.signForm(r1);
        b2.executeForm(r1);
    }

    std::cout << std::endl << "test 3: " << std::endl;
    {
        Bureaucrat b3("b3", 1);
        PresidentialPardonForm p1("p1");
        
        b3.signForm(p1);
        b3.executeForm(p1);
    }
    return 0;
}
