/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:23 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/01 14:26:26 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(const AAnimal &copy);
    AAnimal& operator=(const AAnimal &copy);
    virtual ~AAnimal();
    std::string getType() const;
    virtual void makeSound() const = 0;
};


#endif //AAnimal_HPP
