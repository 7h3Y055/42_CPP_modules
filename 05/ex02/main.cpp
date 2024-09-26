#include "AForm.hpp"

int main()
{
    {
        std::cout << "Test 1" << std::endl;
        Bureaucrat a("A", 1);
        AForm      b("B", 150);

        a.signAForm(b);
    }

    {
        std::cout << std::endl << "Test 2" << std::endl;
        Bureaucrat a("A", 10);
        AForm      b("B", 10);

        a.signAForm(b);
    }

    {
        std::cout << std::endl << "Test 3" << std::endl;
        Bureaucrat a("A", 150);
        AForm      b("B", 10);

        a.signAForm(b);
    }

    return 0;
}
