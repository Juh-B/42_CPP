/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:39 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/11 13:46:41 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|    CREATING DIAMONDTRAP    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	DiamondTrap a("Astronaut");

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          METHODS          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	a.attack("Enemy");

	a.takeDamage(30);
	a.beRepaired(20);

	std::cout << std::endl;

	a.highFivesGuys();
	a.guardGate();

	std::cout << std::endl;
	
	a.whoAmI();

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|   DESTRUCTING CLAPTRAPS   |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	return (0);
}