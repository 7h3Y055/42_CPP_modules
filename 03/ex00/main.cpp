#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("wolf");

    std::cout << std::endl << std::endl;

    b.attack("sheep1");
    b.takeDamage(9);
    b.takeDamage(1);
    b.takeDamage(10);
    b.beRepaired(5);
    b.attack("sheep2");

    std::cout << std::endl << std::endl;

    a.attack("sheep3");
    a.beRepaired(3);
    a.takeDamage(100);

    std::cout << std::endl << std::endl;
    return (0);
}
