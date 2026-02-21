/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:24:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:22:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}



/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	return (*this);
}



/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */


static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}


static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}


static AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}



AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formFunctions[3])(std::string) =
	{
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout
				<< "Intern creates "
				<< name
				<< std::endl;

			return formFunctions[i](target);
		}
	}

	std::cout
		<< "Intern couldn't find form: "
		<< name
		<< std::endl;

	return (NULL);
}
