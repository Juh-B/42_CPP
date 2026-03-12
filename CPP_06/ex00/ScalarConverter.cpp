/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>
# include <cctype>
#include "ScalarConverter.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter(void) {}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

void ScalarConverter::convert(const std::string &literal)
{
	char *endptr;
	double value;

	if (literal.length() == 1 && !isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
	{
		value = std::strtod(literal.c_str(), &endptr);

		if (*endptr != '\0')
		{
			if (*endptr == 'f' && *(endptr + 1) == '\0')
				{}
			else
			{
				std::cout << WHITE_B << "char: " << RESET << "impossible" << std::endl;
				std::cout << WHITE_B << "int: " << RESET << "impossible" << std::endl;
				std::cout << WHITE_B << "float: " << RESET << "impossible" << std::endl;
				std::cout << WHITE_B << "double: " << RESET << "impossible" << std::endl;
				return;
			}
		}
	}

	std::cout << std::fixed << std::setprecision(1);

	// char
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << WHITE_B << "char: " << RESET << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << WHITE_B << "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << WHITE_B << "char: " << RESET << "'" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (std::isnan(value) || std::isinf(value) ||
		value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min())
		std::cout << WHITE_B << "int: " << RESET << "impossible" << std::endl;
	else
		std::cout << WHITE_B << "int: " << RESET << static_cast<int>(value) << std::endl;

	// float
	std::cout << WHITE_B << "float: " << RESET << static_cast<float>(value) << "f" << std::endl;

	// double
	std::cout << WHITE_B << "double: " << RESET << value << std::endl;
}
