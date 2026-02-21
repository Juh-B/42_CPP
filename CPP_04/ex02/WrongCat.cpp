/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:33:12 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 16:16:40 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void WrongCat::makeSound() const
{
	std::cout	<< "Quack, oops, I mean Meow!!!"
				<< std::endl;
}