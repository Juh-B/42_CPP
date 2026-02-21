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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << std::endl << GREEN
			<< "======== Bureaucrats ========"
			<< std::endl << RESET << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Manager", 40);
	Bureaucrat intern("Intern", 150);


	std::cout << std::endl << GREEN
			<< "=========== Forms ==========="
			<< std::endl << RESET << std::endl;

	ShrubberyCreationForm shrub("home");
	std::cout << std::endl;
	RobotomyRequestForm robot("Bender");
	std::cout << std::endl;
	PresidentialPardonForm pardon("Arthur");


	std::cout << std::endl << GREEN
			<< "=========== Sign ============"
			<< std::endl << RESET << std::endl;

	std::cout << intern << std::endl;
	std::cout << mid << std::endl;
	std::cout << boss << std::endl;
	std::cout << std::endl;

    intern.signForm(shrub);
	std::cout << std::endl;

	mid.signForm(robot);
	std::cout << std::endl;

	boss.signForm(pardon);

	std::cout << std::endl << GREEN
		<< "========= Execute ==========" << RESET
		<< std::endl;

	intern.executeForm(shrub);
	std::cout << std::endl;

	mid.executeForm(robot);
	std::cout << std::endl;

	boss.executeForm(pardon);


	std::cout << std::endl << GREEN
			<< "============================="
			<< std::endl << RESET << std::endl;

	return (0);
}
