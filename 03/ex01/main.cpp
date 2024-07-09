#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("wolf");


    a.attack("cheep1");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("cheep2");

    b.beRepaired(3);
    for (int i = 0; i < 12; i++)
        b.attack("cheep3");
    b.beRepaired(3);

	return (0);
}
