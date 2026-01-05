/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_idea[i] = other._idea[i];
	}
	return (*this);
}


/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _idea[index];
	return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >=0 && index < 100)
		_idea[index] = idea;
}
