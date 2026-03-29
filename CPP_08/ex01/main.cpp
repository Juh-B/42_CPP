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

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

#define GREEN	"\033[32m"
#define RESET	"\033[0m"


int main()
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|       42 Main test        |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|       Largest test        |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    Span big(10000);
    std::vector<int> data;

    for (int i = 0; i < 10000; i++)
        data.push_back(rand());

    big.addRange(data.begin(), data.end());

    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest: " << big.longestSpan() << std::endl;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|        Error test         |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    try
    {
        Span small(1);
        small.addNumber(5);
        small.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

	std::cout << std::endl;

	return 0;
}
