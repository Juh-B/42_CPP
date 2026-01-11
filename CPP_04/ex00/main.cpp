/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:33:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:33:33 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|    CORRECT POLYMORPHISM   |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl << WHITE_B
	<< "=========== Types ===========" << RESET
	<< std::endl << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << std::endl << WHITE_B
	<< "========== Sounds ===========" << RESET
	<< std::endl << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl << WHITE_B
	<< "=============================" << RESET
	<< std::endl << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     WRONG POLYMORPHISM    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl << WHITE_B
	<< "=========== Types ===========" << RESET
	<< std::endl << std::endl;

	std::cout << wrongCat->getType() << std::endl;

	std::cout << std::endl << WHITE_B
	<< "========== SOUND ==========" << RESET
	<< std::endl << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl << WHITE_B
	<< "=============================" << RESET
	<< std::endl << std::endl;

	delete wrongMeta;
	delete wrongCat;

	return (0);
}