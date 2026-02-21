/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:16:26 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 13:46:22 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout	<< YELLOW << "ScavTrap" << RESET
				<< " default constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout 	<< YELLOW << "ScavTrap" << RESET
				<< " constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout	<< YELLOW << "ScavTrap" << RESET
				<< " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout	<< YELLOW << "ScavTrap" << RESET
				<< " destructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);

	std::cout	<< YELLOW << "ScavTrap" << RESET
				<< " assignment operator called" << std::endl;

	return (*this);
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< YELLOW << "ScavTrap "
					<< WHITE_B << _name << RESET
					<< " can't attack because it has "
					<< YELLOW << "no hit points!" << RESET
					<< std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout	<< YELLOW << "ScavTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " can't attack" << RESET
					<< ", because it has "
					<< YELLOW << "no energy points left!" << RESET
					<< std::endl;
		return;
	}

	_energyPoints--;
	std::cout	<< YELLOW << "ScavTrap "
				<< WHITE_B << _name << RESET
				<< YELLOW << " attacks "
				<< WHITE_B << target << RESET
				<< ", causing " << _attackDamage << " points of Damage!"
				<< std::endl;
}


void ScavTrap::guardGate()
{
	std::cout	<< YELLOW << "ScavTrap "
				<< WHITE_B << _name << RESET
				<< " is now in "
				<< YELLOW << "Gate keeper mode!" << RESET
				<< std::endl;
}