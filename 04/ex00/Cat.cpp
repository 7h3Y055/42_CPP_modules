/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:35 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:27:35 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &copy):Animal(copy){
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy){
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow 🐱" << std::endl;
}