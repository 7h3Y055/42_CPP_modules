#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
    std::cout << "Default FragTrap constractor called" << std::endl;
    set_name("Default");
    set_hit_point(100);
    set_energy_point(100);
    set_attack_damage(30);
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout << name << " FragTrap constractor called" << std::endl;
    set_hit_point(100);
    set_energy_point(100);
    set_attack_damage(30);
}

FragTrap::~FragTrap()
{
    std::cout << get_name() << " FragTrap destractor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &copy): ClapTrap(copy){
    std::cout << "FragTrap copy constractor called" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(FragTrap &copy){
    std::cout << "FragTrap copy assingment constractor called" << std::endl;
    if (this != &copy){
        this->set_name(copy.get_name());
        this->set_hit_point(copy.get_hit_point());
        this->set_energy_point(copy.get_energy_point());
        this->set_attack_damage(copy.get_attack_damage());
    }
    return *this;
}





void FragTrap::highFivesGuys(void){
    std::cout << get_name() << ", Give me some high fives, guys!" << std::endl;
}