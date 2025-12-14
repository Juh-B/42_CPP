/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:56 by jcosta-b         ###   ########.fr       */
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
