/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:13 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:27:14 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal Default constructor called" << std::endl;
    type = "Non type";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy){
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << "Non type make sound" << std::endl;
}
