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
#include <string>
#include "whatever.hpp"

#define GREEN	"\033[32m"
#define RESET	"\033[0m"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          Interge          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    int a = 2;
    int b = 3;

	std::cout << GREEN << "__ Original __"
			<< RESET << std::endl;

	std::cout << "a = " << a
			<< std::endl
			<< "b = " << b
			<< std::endl;

	std::cout << std::endl << GREEN
			<< "___ Swap ___"
			<< RESET << std::endl;

	::swap(a, b);
    std::cout << "a = " << a
			<< std::endl
			<< "b = " << b
			<< std::endl;

	std::cout << std::endl << GREEN
			<< "___ Min & Max ___"
			<< RESET << std::endl;

    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          String           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

	std::cout << GREEN << "__ Original __"
			<< RESET << std::endl;

	std::cout << "c = " << c
			<< std::endl
			<< "d = " << d
			<< std::endl;

	std::cout << std::endl << GREEN
			<< "___ Swap ___"
			<< RESET << std::endl;

	::swap(c, d);
    std::cout << "c = " << c
			<< std::endl
			<< "d = " << d
			<< std::endl;

	std::cout << std::endl << GREEN
			<< "___ Min & Max ___"
			<< RESET << std::endl;

    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << std::endl;

    return 0;
}
