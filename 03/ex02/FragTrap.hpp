#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap &copy);
    FragTrap& operator=(FragTrap &copy);
    ~FragTrap();

    void highFivesGuys(void);
};




#endif