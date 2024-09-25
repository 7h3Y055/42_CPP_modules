/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:10 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:49:39 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	Dog dog;
	Cat cat;

	std::cout << std::endl << std::endl;
	Dog dog_copy(dog);
	Cat cat_copy(cat);

	std::cout << std::endl << std::endl;

	// dog.compare(dog_copy);
	// cat.compare(cat_copy);
	std::cout << std::endl;


	std::cout << "[TEST] array animals" << std::endl;
    int n = 4;
	const Animal *animal_array[n];
	std::cout << std::endl;

	for (int i = 0; i < n / 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	for (int i = n / 2; i < n; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
		delete animal_array[i];

	std::cout << std::endl;
}
