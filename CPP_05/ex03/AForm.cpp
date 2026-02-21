/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

AForm::AForm(void)
		: _name("default"),
		_isSigned(false),
		_gradeSign(150),
		_gradeExec(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
		: _name(name),
		_isSigned(false),
		_gradeSign(gradeSign),
		_gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();

	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();

	std::cout << "AForm constructor called for "
			<< YELLOW << name << RESET << std::endl;
}

AForm::AForm(const AForm& other)
		: _name(other._name),
		_isSigned(other._isSigned),
		_gradeSign(other._gradeSign),
		_gradeExec(other._gradeExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

/* ************************************************************************** */
/*                                Operator                                    */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName()
		<< ", signed: "
		<< form.getIsSigned()
		<< ", grade sign: "
		<< form.getGradeSign()
		<< ", grade exec: "
		<< form.getGradeExec();

    return (os);
}

/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

int AForm::getGradeSign(void) const
{
	return _gradeSign;
}

int AForm::getGradeExec(void) const
{
	return _gradeExec;
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();

    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();

	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();

	executeAction();
}

/* ************************************************************************** */
/*                                Exceptions                                  */
/* ************************************************************************** */

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed!";
}
