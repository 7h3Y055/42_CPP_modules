#include "ScavTrap.hpp"


ScavTrap::ScavTrap():ClapTrap(), keeper_mode(0){
    std::cout << "Default ScavTrap constractor called" << std::endl;
    set_name("Default");
    set_hit_point(100);
    set_energy_point(50);
    set_attack_damage(20);
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name), keeper_mode(0){
    std::cout << name << " ScavTrap constractor called" << std::endl;
    set_hit_point(100);
    set_energy_point(50);
    set_attack_damage(20);
}

ScavTrap::ScavTrap(ScavTrap &copy): ClapTrap(copy){
    std::cout << "Copy ScavTrap constractor called" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap &copy){
    std::cout << "Copy assignment ScavTrap constractor called" << std::endl;
    if (&copy != this){
        this->set_name(copy.get_name());
        this->set_hit_point(copy.get_hit_point());
        this->set_energy_point(copy.get_energy_point());
        this->set_attack_damage(copy.get_attack_damage());
        this->keeper_mode = copy.keeper_mode;
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << get_name() << " ScavTrap destractor called" << std::endl;
}


void ScavTrap::attack(const std::string& target){
    if (this->get_energy_point())
    {
        this->set_energy_point(this->get_energy_point() - 1);
        std::cout << "ScavTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
    }else
        std::cout << "ScavTrap " << this->get_name() << " can't attacks " << target << ", energy points is " << this->get_attack_damage() << " !" << std::endl;

}


void ScavTrap::guardGate(){
    if (keeper_mode)
        std::cout << get_name() << " is already in Gate keeper mode" << std::endl;
    else{
        std::cout << get_name() << " now in Gate keeper mode" << std::endl;
        keeper_mode = 1;
    }
}
