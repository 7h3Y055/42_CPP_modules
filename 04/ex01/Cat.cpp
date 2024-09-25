/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:35 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/02 16:15:11 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
}

Cat::Cat(const Cat &copy):Animal(copy){
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy){
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &copy){
        this->type = copy.type;
        for (int i = 0; i < 100; i++){
            this->brain->set_ideas(i,copy.get_brain_ideas()[i]);
        }
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow 🐱" << std::endl;
}

std::string* Cat::get_brain_ideas() const{
    return brain->get_ideas();
}

void Cat::compare(Cat const &cat) const
{
	std::cout << std::endl;
	std::cout << "this cat brain heap address: " << (void*)this->brain << std::endl;
	std::cout << "other cat brain heap address: " << (void*)cat.brain << std::endl;
	std::cout << std::endl;
	std::cout << "this ideas\t |\tOther ideas" << std::endl;
    std::cout << "-------------------------------------";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->get_ideas())[i] << "\t\t |\t\t" << ((cat.brain)->get_ideas())[i] << std::endl;
	std::cout << std::endl;
}