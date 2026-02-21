/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Form::Form(void)
		: _name("default"),
		_isSigned(false),
		_gradeSign(150),
		_gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
		: _name(name),
		_isSigned(false),
		_gradeSign(gradeSign),
		_gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();

	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();

	std::cout << "Form constructor called for " << name << std::endl;
}

Form::Form(const Form& other)
		: _name(other._name),
		_isSigned(other._isSigned),
		_gradeSign(other._gradeSign),
		_gradeExec(other._gradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

/* ************************************************************************** */
/*                                Operator                                    */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Form& form)
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

std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

int Form::getGradeSign(void) const
{
	return _gradeSign;
}

int Form::getGradeExec(void) const
{
	return _gradeExec;
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw GradeTooLowException();

    _isSigned = true;
}

/* ************************************************************************** */
/*                                Exceptions                                  */
/* ************************************************************************** */

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}
