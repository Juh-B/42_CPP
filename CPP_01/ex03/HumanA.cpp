/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:34:53 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:34:55 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	:	_name(name), _weapon(weapon)
{}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const
{
	std::cout	<< _name << " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}