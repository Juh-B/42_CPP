/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:42:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:44:59 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) { return ; }
Harl::~Harl( void ) { return ; }

void Harl::debug(void)
{
	std::cout << std::endl
	<< GREEN << "[ DEBUG ]" << RESET << std::endl
	<< "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
	<< "I really do!"
	<< std::endl;
}

void Harl::info(void)
{
	std::cout << std::endl
	<< GREEN << "[ INFO ]" << RESET << std::endl
	<< "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger! "
	<< "If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning(void)
{
	std::cout << std::endl
	<< YELLOW << "[ WARNING ]" << RESET << std::endl
	<< "I think I deserve to have some extra bacon for free. "
	<< "I've been coming for years whereas you started working "
	<< "here since last month."
	<< std::endl;
}

void Harl::error(void)
{
	std::cout << std::endl
	<< RED << "[ ERROR ]" << RESET << std::endl
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level)
{
	int	levelIndex = -1;

	std::string levels[4] = {
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
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex)
	{
		case 0:
			for (int i = levelIndex; i < 4; i++)
			{ (this->*functions[i])(); }
			break;
		case 1:
			for (int i = levelIndex; i < 4; i++)
			{ (this->*functions[i])(); }
			break;
		case 2:
			for (int i = levelIndex; i < 4; i++)
			{ (this->*functions[i])(); }
			break;
		case 3:
			for (int i = levelIndex; i < 4; i++)
			{ (this->*functions[i])(); }
			break;
		default:
			std::cout << std::endl
				<< "[ Puff... Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}