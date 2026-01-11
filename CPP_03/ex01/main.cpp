/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:39 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:15:51 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     CREATING SCAVTRAPS    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	ScavTrap a("Super_Astronaut");
	ScavTrap b("Enemy");

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          METHODS          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	a.attack("Enemy");

	b.takeDamage(20);
	b.guardGate();

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|   DESTRUCTING CLAPTRAPS   |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	return (0);
}