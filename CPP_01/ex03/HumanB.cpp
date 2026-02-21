/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:35:11 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:35:12 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
	:	_name(name), _weapon(NULL)
{}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (_weapon)
	{
		std::cout	<< _name << " attacks with their "
					<< _weapon->getType()
					<< std::endl;

	}
	else
	{
		std::cout	<< _name << " has no weapon"
					<< std::endl;
	}
}