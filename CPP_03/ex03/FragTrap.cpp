/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:18:59 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 13:45:50 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout	<< BLUE << "FragTrap" << RESET
				<< " default constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout 	<< BLUE << "FragTrap" << RESET
				<< " constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout	<< BLUE << "FragTrap" << RESET
				<< " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout	<< BLUE << "FragTrap" << RESET
				<< " destructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);

	std::cout	<< BLUE << "FragTrap" << RESET
				<< " assignment operator called" << std::endl;

	return (*this);
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< BLUE << "FragTrap "
					<< WHITE_B << _name << RESET
					<< " can't attack because it has "
					<< YELLOW << "no hit points!" << RESET
					<< std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout	<< BLUE << "FragTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " can't attack" << RESET
					<< ", because it has "
					<< YELLOW << "no energy points left!" << RESET
					<< std::endl;
		return;
	}

	_energyPoints--;
	std::cout	<< BLUE << "FragTrap "
				<< WHITE_B << _name << RESET
				<< YELLOW << " attacks "
				<< WHITE_B << target << RESET
				<< ", causing " << _attackDamage << " points of Damage!"
				<< std::endl;
}


void FragTrap::highFivesGuys()
{
	std::cout	<< BLUE << "FragTrap "
				<< WHITE_B << _name << RESET
				<< " requests a "
				<< GREEN << "positive high five! ✋" << RESET
				<< std::endl;
}