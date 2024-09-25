/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:11:56 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:11:57 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain &copy);
    Brain& operator=(const Brain &copy);
    ~Brain();
    std::string* get_ideas();
    void    set_ideas(int index, std::string idea);
};



#endif //BRAIN_HPP