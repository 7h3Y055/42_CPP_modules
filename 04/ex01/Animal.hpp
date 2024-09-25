/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:23 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:49:42 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &copy);
    Animal& operator=(const Animal &copy);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
};


#endif //ANIMAL_HPP
