/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void Dog::makeSound() const
{
	std::cout	<< "Woooof!!!"
				<< std::endl;
}


/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

Brain* Dog::getBrain() const
{
	return brain;
}
