#include "HumanA.hpp"

void    HumanA::attack(){
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string n, Weapon &w):weapon(w),name(n){

}

HumanA::~HumanA(){

}
