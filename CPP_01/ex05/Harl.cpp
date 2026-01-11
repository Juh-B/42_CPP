/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:42:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:42:26 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) { return ; }
Harl::~Harl( void ) { return ; }

void Harl::debug(void)
{
	std::cout
	<< "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
	<< "I really do!"
	<< std::endl;
}

void Harl::info(void)
{
	std::cout
	<< "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger! "
	<< "If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning(void)
{
	std::cout
	<< "I think I deserve to have some extra bacon for free. "
	<< "I've been coming for years whereas you started working "
	<< "here since last month."
	<< std::endl;
}

void Harl::error(void)
{
	std::cout
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void (Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Wow! Harl is silent..." << std::endl;
}