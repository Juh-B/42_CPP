/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:11:50 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Look! The Zombie "
			  << BLUE << "xxx" << RESET
			  << " has risen from the dead!"
			  << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Oh no... The Zombie "
			  << GREEN << this->_name << RESET
			  << " died again..."
			  << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
	this->_name = name;
}
