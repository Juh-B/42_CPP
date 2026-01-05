/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
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
