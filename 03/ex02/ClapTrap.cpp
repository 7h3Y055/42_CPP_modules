#include "ClapTrap.hpp"


ClapTrap::ClapTrap():name("default"), hit_point(10), energy_point(10), attack_damage(0){
    std::cout << "Default ClapTrap constractor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):name(_name), hit_point(10), energy_point(10), attack_damage(0){
    std::cout << name << " ClapTrap constractor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
    std::cout << "Copy ClapTrap constractor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &r){
    std::cout << "Copy assignment ClapTrap constractor called" << std::endl;
    if (this != &r){
        this->attack_damage = r.attack_damage;
        this->energy_point = r.energy_point;
        this->hit_point = r.hit_point;
        this->name = r.name;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << this->name << " ClapTrap destractor called" << std::endl;
}








void ClapTrap::attack(const std::string& target){
    if (this->energy_point)
    {
        this->energy_point--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }else
        std::cout << "ClapTrap " << this->name << " can't attacks " << target << ", energy points is " << this->attack_damage << " !" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hit_point <= 0){
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return ;
    }
    this->hit_point -= amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
    if (this->hit_point)
        std::cout << "ClapTrap " << this->name << " take damage " << amount << ", hit points is " << this->hit_point << " now!" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->energy_point && this->hit_point > 0)
    {
        this->energy_point--;
        this->hit_point += amount;
        std::cout << "ClapTrap " << this->name << " be repaired " << amount << ", hit points is " << this->hit_point << " now!" << std::endl;
    }else if (this->hit_point > 0)
        std::cout << "ClapTrap " << this->name << " can't repaired " << amount << ", energy point is " << this->energy_point << " !" << std::endl;
    else{
        std::cout << "ClapTrap " << this->name << " is dead can't repaire!" << std::endl;
    }
}


std::string ClapTrap::get_name(){
    return name;
}

long ClapTrap::get_hit_point(){
    return hit_point;
}

long ClapTrap::get_energy_point(){
    return energy_point;
}

long ClapTrap::get_attack_damage(){
    return attack_damage;
}


void ClapTrap::set_name(std::string const name){
    this->name = name;
}

void ClapTrap::set_hit_point(long const n){
    hit_point = n;
}

void ClapTrap::set_energy_point(long const n){
    energy_point = n;
}

void ClapTrap::set_attack_damage(long const n){
    attack_damage = n;
}
