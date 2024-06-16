#include <iostream>

class ClapTrap
{
private:
    std::string name;
    size_t hit_point;
    size_t energy_point;
    size_t attack_damage;
public:
    ClapTrap(); 
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};