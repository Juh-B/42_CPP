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
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|                           |" << std::endl
	<< "|  1 HIGH <------> LOW 150  |" << std::endl
	<< "|                           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;


	std::cout << std::endl << GREEN
			<< "======== Bureaucrats ========"
			<< std::endl << RESET << std::endl;

	Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);


	std::cout << std::endl << GREEN
			<< "=========== Forms ==========="
			<< std::endl << RESET << std::endl;

    Form contract("Contract", 50, 50);


	std::cout << std::endl << GREEN
			<< "=========== Sign ============"
			<< std::endl << RESET << std::endl;

	std::cout << intern << std::endl;
    intern.signForm(contract);

	std::cout << std::endl;
	std::cout << boss << std::endl;
    boss.signForm(contract);

	std::cout << std::endl;
    std::cout << contract << std::endl;

	std::cout << std::endl << GREEN
			<< "============================="
			<< std::endl << RESET << std::endl;

	return (0);
}
