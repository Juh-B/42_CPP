/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:32:35 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 12:12:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define GREEN	"\033[32m"
#define RESET	"\033[0m"

int main()
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|         Basic Test        |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << std::endl;
	}


	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|         Copy Test         |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    Array<int> copy(numbers);

    numbers[0] = 999;

    std::cout << "Original: " << numbers[0] << std::endl;
    std::cout << "Copy: " << copy[0] << std::endl;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|       Out of bounds       |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught!" << std::endl;
    }

	std::cout << std::endl;

    return 0;
}
