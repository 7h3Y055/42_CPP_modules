#include "Form.hpp"

int main()
{

    {
        std::cout << "Test 1" << std::endl;
        Bureaucrat a("A", 1);
        Form      b("B", 150);

        a.signForm(b);
    }

    {
        std::cout << std::endl << "Test 2" << std::endl;
        Bureaucrat a("A", 10);
        Form      b("B", 10);

        a.signForm(b);
    }

    {
        std::cout << std::endl << "Test 3" << std::endl;
        Bureaucrat a("A", 150);
        Form      b("B", 10);

        a.signForm(b);
    }

    return 0;
}
