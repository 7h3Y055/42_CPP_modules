#include "Zombie.hpp"

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ){
    Zombie *zombie = new Zombie(name);
    return zombie;
}

void    Zombie::set_name(std::string name){
    this->name = name;
}



Zombie::Zombie(){

}

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name << ": destractor" << std::endl;
}