/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:35:37 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:35:38 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
	:	_type(type)
{}

Weapon::~Weapon(void) {}

void Weapon::setType(const std::string& type)
{
	_type = type;
}

const std::string& Weapon::getType(void) const
{
	return _type;
}