#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "default constracter called" << std::endl;
    this->name = "default";
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;    
}

ClapTrap::ClapTrap(std::string name){
    std::cout << name << " constracter called" << std::endl;
    this->name = name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << name << " destractor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << name  << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << name << " takeDamage called" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << name << " beRepaired called" << std::endl;
}
