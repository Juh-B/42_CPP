/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void)
	: _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();

	if (grade > 150)
		throw GradeTooLowException();

	_grade = grade;
	std::cout << "Bureaucrat constructor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

/* ************************************************************************** */
/*                                Operator                                    */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{

	os << WHITE_B << bureaucrat.getName() << RESET
	<< ", bureaucrat with classification "
	<< GREEN << bureaucrat.getGrade() << RESET;

	return (os);
}

/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();

	_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);

		std::cout << _name
				<< " signed "
				<< form.getName()
				<< std::endl;

	}

	catch (std::exception& e)
	{
		std::cout << _name
				<< " couldn't sign "
				<< form.getName()
				<< " because "
				<< e.what()
				<< std::endl;
	}
}

/* ************************************************************************** */
/*                                Exceptions                                  */
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
