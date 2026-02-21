/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:11 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 13:52:05 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) :
				_name("Unnamed"),
				_hitPoints(10),
				_energyPoints(10),
				_attackDamage(0)
{
	std::cout	<< "ClapTrap default constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
				_name(name),
				_hitPoints(10),
				_energyPoints(10),
				_attackDamage(0)
{
	std::cout 	<< "ClapTrap constructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout	<< "ClapTrap destructor called for "
				<< WHITE_B << _name << RESET
				<< std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;

	return (*this);
}


/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout	<< "ClapTrap "
					<< WHITE_B << _name << RESET
					<< " can't attack because it has "
					<< YELLOW << "no hit points!" << RESET
					<< std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout	<< "ClapTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " can't attack" << RESET
					<< ", because it has "
					<< YELLOW << "no energy points left!" << RESET
					<< std::endl;
		return;
	}

	_energyPoints--;
	std::cout	<< "ClapTrap " << WHITE_B << _name << RESET
				<< YELLOW << " attacks "
				<< WHITE_B << target << RESET
				<< ", causing " << _attackDamage << " points of Damage!"
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout 	<< "ClapTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " can't take damage" << RESET
					<< " because it's already dead!"
					<< std::endl;
        return;
    }

    if (amount >= static_cast<unsigned int>(_hitPoints))
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout	<< "ClapTrap "
				<< WHITE_B << _name << RESET
				<< " takes " << RED_B << amount << RESET
				<< " points of " << RED << "damage!" << RESET
				<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout	<< "ClapTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " cannot be repaired" << RESET
					<< " because it's dead!"
					<< std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout	<< "ClapTrap "
					<< WHITE_B << _name << RESET
					<< YELLOW << " can't be repaired" << RESET
					<< ", because it has "
					<< YELLOW << "no energy points left!" << RESET
					<< std::endl;
        return;
    }

    _energyPoints--;
    _hitPoints += amount;

    std::cout	<< "ClapTrap "
				<< WHITE_B << _name << RESET
				<< GREEN << " repairs" << RESET
				<< " itself for "
				<< GREEN_B << amount << RESET
				<< " hit points!"
				<< std::endl;
}