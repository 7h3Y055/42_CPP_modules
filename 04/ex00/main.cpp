/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:10 by ybouchma          #+#    #+#             */
/*   Updated: 2024/08/03 10:25:35 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main( void )
{
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "-------------------------------------------" << std::endl;


	std::cout  << std::endl << std::endl << "\t[Animal/Cat tests]" << std::endl << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();




	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "-------------------------------------------" << std::endl;
	

	std::cout  << std::endl << "\t[Wrong Animal/Cat tests]" << std::endl << std::endl;
	std::cout << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();



	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong_cat;
	delete wrong_animal;
	std::cout << "-------------------------------------------" << std::endl;
}