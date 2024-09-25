/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:27 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:26:28 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(){
    type = "Non type";
    std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy){
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &copy){
    std::cout << "AAnimal Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const{
    return type;
}

void AAnimal::makeSound() const{
    std::cout << "Non type make sound!" << std::endl;

}
