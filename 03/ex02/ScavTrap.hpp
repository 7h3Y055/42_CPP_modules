#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
private:
    bool keeper_mode;
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &copy);
    ScavTrap& operator=(ScavTrap &copy);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};



#endif