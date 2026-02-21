/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:32:56 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 16:16:20 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : type("Wrong Animal")
{
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void WrongAnimal::makeSound() const
{
	std::cout	<< "* Generic Wrong Animal Sound *"
				<< std::endl;
}

/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

std::string WrongAnimal::getType() const
{
	return type;
}