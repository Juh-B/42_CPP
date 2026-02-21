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
#include "Intern.hpp"

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
		<< "========= Execute =========="
		<< std::endl << RESET << std::endl;

	intern.executeForm(shrub);
	std::cout << std::endl;

	mid.executeForm(robot);
	std::cout << std::endl;

	boss.executeForm(pardon);


	std::cout << std::endl << GREEN
	<< "=========== Intern =========="
	<< std::endl << RESET << std::endl;

	Intern someRandomIntern;

	AForm* f1;
	AForm* f2;
	AForm* f3;
	AForm* f4;


	f1 = someRandomIntern.makeForm("shrubbery creation", "garden");
	std::cout << std::endl;
	f2 = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
	std::cout << std::endl;
	f4 = someRandomIntern.makeForm("invalid form", "Nobody");

	std::cout << std::endl;

	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete f1;
	}

	std::cout << std::endl;

	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete f2;
	}

	std::cout << std::endl;

	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
		delete f3;
	}

	if (f4)
		delete f4;

	std::cout << std::endl << GREEN
			<< "============================="
			<< std::endl << RESET << std::endl;

	return (0);
}
