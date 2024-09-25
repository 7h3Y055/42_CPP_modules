/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:27 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:26:28 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    type = "Non type";
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy){
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal &copy){
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "Non type make sound!" << std::endl;

}
