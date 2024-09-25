/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:15 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/02 20:06:47 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>


class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal& operator=(const WrongAnimal &copy);
    virtual ~WrongAnimal();
    std::string getType() const;
    virtual void makeSound() const;
};


#endif //WrongAnimal_HPP
