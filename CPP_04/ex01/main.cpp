/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:33:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:35:58 by jcosta-b         ###   ########.fr       */
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
	<< "|       DEEP COPY TEST      |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	std::cout	<< WHITE_B << "======== Dog 1 ========" << RESET
				<< std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I'm starving... I'll go eat something.");

	std::cout	<< std::endl << WHITE_B
				<< "======== Dog 2 ========" << RESET
				<< std::endl;
    Dog dog2 = dog1;
    dog2.getBrain()->setIdea(0, "I want sleep. ZzzZzz...");

	std::cout	<< std::endl << WHITE_B
				<< "======== Ideas ========" << RESET
				<< std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	// -----------------------------------------------------

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|  ASSIGNMENT OPERATOR TEST |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	std::cout	<< WHITE_B << "======== Cat 1 ========" << RESET
				<< std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "I want a big fish!");

	std::cout	<< std::endl << WHITE_B
				<< "======== Cat 2 ========" << RESET
				<< std::endl;
    Cat cat2;
    cat2 = cat1;
    cat2.getBrain()->setIdea(0, "I want to drink some milk");

	std::cout	<< std::endl << WHITE_B
				<< "======== Ideas ========" << RESET
				<< std::endl;
    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

	// -------------------------------------------------

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|        INDEX TEST         |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE / 2)
			std::cout << std::endl;
		std::cout << "Index -> " << i << std::endl;
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
			animals[i] = new Cat();
    }

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|       DESTRUCTING         |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    std::cout	<< std::endl << WHITE_B
				<< "======== From Index ========" << RESET
				<< std::endl << std::endl;

    for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE / 2)
			std::cout << std::endl;
		std::cout << "Index -> " << i << std::endl;
        delete animals[i];
	}

	std::cout	<< std::endl << WHITE_B
				<< "======== Others ========" << RESET
				<< std::endl << std::endl;

	return (0);
}