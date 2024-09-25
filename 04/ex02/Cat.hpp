/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:40 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/02 18:11:02 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat &copy);
    Cat& operator=(const Cat &copy);
    ~Cat();
    void makeSound() const;
    std::string* get_brain_ideas() const;
    void compare(Cat const &cat) const;
};

# endif //CAT_HPP
