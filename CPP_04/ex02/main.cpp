/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:32:35 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 12:12:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 4

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     ABSTRACT ANIMALS      |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	Animal* animals[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE / 2)
			std::cout << std::endl;
		std::cout << "Animal " << i << std::endl;
		if (i < SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout	<< std::endl << WHITE_B
				<< "===== Types and Sounds ======" << RESET
				<< std::endl << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout	<< "Animal " << i
					<< " -> It's a "<< GREEN << animals[i]->getType() << RESET
					<< ", so it goes " << WHITE_B;
		animals[i]->makeSound();
		std::cout	<< RESET << std::endl;
	}


    std::cout	<< std::endl << WHITE_B
				<< "======== Destructing ========" << RESET
				<< std::endl << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE / 2)
			std::cout << std::endl;
		std::cout << "Animal " << i << std::endl;
		delete animals[i];
	}

	return (0);
}
