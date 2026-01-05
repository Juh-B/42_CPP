/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}


/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

std::string Animal::getType() const
{
	return type;
}
