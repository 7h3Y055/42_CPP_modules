/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:05 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/02 18:11:02 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog &copy):AAnimal(copy){
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy){
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &copy){
        this->type = copy.type;
        for (int i = 0; i < 100; i++){
            this->brain->set_ideas(i,copy.get_brain_ideas()[i]);
        }
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Bark 🐕" << std::endl;
}

std::string* Dog::get_brain_ideas() const{
    return brain->get_ideas();
}

void Dog::compare(Dog const &dog) const
{
	std::cout << std::endl;
	std::cout << "this dog brain heap address: " << (void*)this->brain << std::endl;
	std::cout << "other dog brain heap address: " << (void*)dog.brain << std::endl;
	std::cout << std::endl;
	std::cout << "this ideas\t |\tOther ideas" << std::endl;
    std::cout << "-------------------------------------";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->get_ideas())[i] << "\t\t |\t\t" << ((dog.brain)->get_ideas())[i] << std::endl;
	std::cout << std::endl;
}