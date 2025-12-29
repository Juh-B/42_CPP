/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:32:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
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
