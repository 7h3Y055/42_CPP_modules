#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat test1("test", 0);
    Bureaucrat test2("test", 151);
    
    Bureaucrat a("a", 3);
    Bureaucrat b("b", 148);


    std::cout << std::endl;


    std::cout << a.getName() << ":" << a.getGrade() << std::endl;
    std::cout << b.getName() << ":" << b.getGrade() << std::endl;
    a.increment();
    b.decrement();

    std::cout << std::endl;

    std::cout << a.getName() << ":" << a.getGrade() << std::endl;
    std::cout << b.getName() << ":" << b.getGrade() << std::endl;
    a.increment();
    b.decrement();

    std::cout << std::endl;

    std::cout << a.getName() << ":" << a.getGrade() << std::endl;
    std::cout << b.getName() << ":" << b.getGrade() << std::endl;
    a.increment();
    b.decrement();
    return 0;
}
