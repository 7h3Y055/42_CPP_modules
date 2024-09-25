#include "ScavTrap.hpp"

int main()
{
	ScavTrap c;
	ScavTrap d("wolf");
	std::cout << std::endl << std::endl;

	c.attack("sheep1");
	c.takeDamage(10);
	c.beRepaired(5);
	c.beRepaired(5);
	c.guardGate();
	c.guardGate();

	std::cout << std::endl << std::endl;

	d.attack("sheep2");
	d.takeDamage(101);
	d.takeDamage(15);
	c.beRepaired(5);
	d.attack("sheep3");

	std::cout << std::endl << std::endl;
	return (0);
}
