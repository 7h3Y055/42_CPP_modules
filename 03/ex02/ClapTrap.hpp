#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
private:
    std::string name;
    long hit_point;
    long energy_point;
    long attack_damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &r);
    ~ClapTrap();


    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string get_name();
    long get_hit_point();
    long get_energy_point();
    long get_attack_damage();

    void set_name(std::string const name);
    void set_hit_point(long const n);
    void set_energy_point(long const n);
    void set_attack_damage(long const n);
};



#endif