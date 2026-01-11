/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:39 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:18:36 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|     CREATING FRAGTRAP    |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	FragTrap a("Mega_Astronaut");
	FragTrap b("Enemy");

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          METHODS          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	a.attack("Enemy");

	b.takeDamage(30);
	b.highFivesGuys();

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|   DESTRUCTING CLAPTRAPS   |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	return (0);
}