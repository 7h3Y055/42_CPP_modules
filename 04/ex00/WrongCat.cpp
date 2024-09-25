/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:18 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:27:24 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(){
    std::cout << "WrongCat Default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy){
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &copy){
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}


WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "WrongMeow 🐱" << std::endl;
}