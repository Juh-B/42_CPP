/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:39 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:14:40 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     CREATING CLAPTRAPS    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	ClapTrap a("42_Astronaut");
	ClapTrap b("Enemy");
	ClapTrap c;

	c = a;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          METHODS          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	a.attack("Enemy");
	b.takeDamage(3);
	b.beRepaired(2);

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     OUT OF LIFE POINTS    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	b.attack("42_Astronalt");
	a.takeDamage(10);

	std::cout << std::endl;

	a.attack("Enemy");
	a.takeDamage(3);
	a.beRepaired(2);

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|       OUT OF ENERGY       |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	c.attack("Enemy");
	c.beRepaired(1);
	c.attack("Enemy");
	c.beRepaired(1);
	c.attack("Enemy");
	c.beRepaired(1);
	c.attack("Enemy");
	c.beRepaired(1);
	c.attack("Enemy");
	c.beRepaired(1);
	std::cout << std::endl;

	c.attack("Enemy");
	c.beRepaired(1);

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|   DESTRUCTING CLAPTRAPS   |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	return (0);
}