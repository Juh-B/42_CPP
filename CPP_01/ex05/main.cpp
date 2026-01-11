/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:42:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:42:48 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"

int main(void)
{
	Harl harl;

	std::cout	<< "So... Harl is going to complain about..." << std::endl;

	std::cout << std::endl << GREEN << "~> DEBUG" << RESET << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << GREEN << "~> INFO" << RESET << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << YELLOW << "~> WARNING" << RESET << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << RED << "~> ERROR" << RESET << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << BLUE << "~> INVALID" << RESET << std::endl;
	harl.complain("INVALID");

	std::cout	<< std::endl << "Oh! Maybe it's over. "
				<< "Quick, let's run before he starts again!!!"
				<< std::endl;

	return 0;
}