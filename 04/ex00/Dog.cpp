/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:05 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:23:04 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &copy):Animal(copy){
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy){
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Bark 🐕" << std::endl;
}