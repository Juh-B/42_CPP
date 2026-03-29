/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Span::Span(unsigned int N)
	: _maxSize(N) {}

Span::Span(const Span& other)
	: 	_maxSize(other._maxSize),
		_numbers(other._numbers)
	{}

Span::~Span(void) {}

/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");

	_numbers.push_back(n);
}

int Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());

	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 0; i < temp.size() - 1; i++)
	{
		int diff = temp[i + 1] - temp[i];
		if (diff < minSpan)
			minSpan = diff;
	}

	return minSpan;
}

int Span::longestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}
