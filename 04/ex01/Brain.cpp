/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:12:04 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:34:45 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain(){
    std::cout << "Brain Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++){
        ideas[i] = "ideas";
    }
}

Brain::Brain(const Brain &copy){
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy){
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &copy)
        for (int i = 0; i < 100; i++){
            this->ideas[i] = copy.ideas[i];
    }
    return *this;
}


Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}


std::string* Brain::get_ideas(){
    return ideas;
}

void    Brain::set_ideas(int index, std::string idea){
    ideas[index] = idea;
}
