/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) :
			ClapTrap("default_clap_name"),
			ScavTrap(),
			FragTrap(),
			_name("Default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout	<< GREEN << "DiamondTrap" << RESET
				<< " default constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
			ClapTrap(name + "_clap_name"),
			ScavTrap(name),
			FragTrap(name),
			_name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout	<< GREEN << "DiamondTrap" << RESET
				<< " constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
			ClapTrap(other),
			ScavTrap(other),
			FragTrap(other)
{
	std::cout	<< GREEN << "DiamondTrap" << RESET
				<< " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout	<< GREEN << "DiamondTrap" << RESET
				<< " destructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}

	std::cout	<< GREEN << "DiamondTrap" << RESET
				<< " assignment operator called" << std::endl;

	return (*this);
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(void)
{
	std::cout	<< GREEN << "DiamondTrap name: "
				<< WHITE_B << _name << RESET
				<< std::endl;

	std::cout	<< "ClapTrap name: "
				<< WHITE_B << _name << RESET
				<< std::endl;
}
