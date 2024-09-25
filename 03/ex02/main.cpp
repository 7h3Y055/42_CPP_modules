#include "FragTrap.hpp"

int main()
{
	{
		FragTrap e;
		FragTrap f("wolf");
		std::cout << std::endl << std::endl;

		e.highFivesGuys();
		e.attack("sheep");
		e.takeDamage(1);
		e.takeDamage(10);
		e.takeDamage(1);
		e.attack("sheep");
		f.highFivesGuys();
		std::cout << std::endl << std::endl;
	}
	return (0);
}
