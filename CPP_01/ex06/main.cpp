/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:42:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:44:29 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr	<< "Usage: ./harlFilter <level>"
					<< std::endl
					<< "Level -> DEBUG | INFO | WARNING | ERROR"
					<< std::endl;
		return 1;
	}

	std::cout	<< "So... Harl is going to complain about..." << std::endl;

	harl.complain(argv[1]);

	return 0;
}