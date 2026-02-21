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

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|                           |" << std::endl
	<< "|  1 HIGH <------> LOW 150  |" << std::endl
	<< "|                           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	try
	{
		std::cout << std::endl << GREEN
		<< "========= INCREMENT =========" << std::endl
		<< RESET << std::endl;

		Bureaucrat a("Bartolomeu", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;


		std::cout << std::endl << GREEN
		<< "========= DECREMENT =========" << std::endl
		<< RESET << std::endl;

		Bureaucrat b("Betinho", 149);
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << b << std::endl;


		std::cout << std::endl;
		// Exceptions
		a.incrementGrade();
		b.decrementGrade();
	}

	catch (std::exception &e)
	{
		std::cout << std::endl << GREEN
		<< "========= EXCEPTION =========" << std::endl
		<< RESET << std::endl;
		std::cout << "Exception: " << YELLOW
				<< e.what() << RESET
				<< std::endl << std::endl;
	}

	return (0);
}
