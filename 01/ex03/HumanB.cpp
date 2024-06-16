#include "HumanB.hpp"

void    HumanB::attack(){
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}


HumanB::HumanB(){
	this->name = "default";
}


HumanB::HumanB(std::string name){
    this->name = name;
}

HumanB::~HumanB(){

}
