/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:34:50 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 15:37:34 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

int main(void)
{
	std::cout << std::endl;
	std::cout << GREEN
	<< "============================" << std::endl
	<< "|      SUBJECT TESTS       |" << std::endl
	<< "============================" << RESET
	<< std::endl << std::endl;

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// ------------------------------------------------------
	std::cout << std::endl << std::endl;

	std::cout << GREEN
	<< "============================" << std::endl
	<< "|     STARTING My TESTS    |" << std::endl
	<< "============================" << RESET << std::endl;

	Fixed A;
	Fixed B(10);
	Fixed C(42.42f);
	Fixed D(B);

	A = Fixed(123.456f);

	std::cout << std::endl;

	std::cout << "===== TO FLOAT / TO INT =====" << std::endl;
	std::cout << "A = " << A << " | int: " << A.toInt() << std::endl;
	std::cout << "B = " << B << " | float: " << B.toFloat() << std::endl;
	std::cout << "C = " << C << " | int: " << C.toInt() << std::endl;
	std::cout << "D = " << D << " | int: " << D.toInt() << std::endl;

	std::cout << std::endl;

	std::cout << "===== COMPARISON OPERATORS =====" << std::endl;
	std::cout << "B > C  = " << (B > C) << std::endl;
	std::cout << "B < C  = " << (B < C) << std::endl;
	std::cout << "B >= D = " << (B >= D) << std::endl;
	std::cout << "B <= D = " << (B <= D) << std::endl;
	std::cout << "B == D = " << (B == D) << std::endl;
	std::cout << "B != C = " << (B != C) << std::endl;

	std::cout << std::endl;

	std::cout << "===== ARITHMETIC OPERATORS =====" << std::endl;
	Fixed x(5.5f);
	Fixed y(2);

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << std::endl;

	std::cout << "===== INCREMENT / DECREMENT =====" << std::endl;
	Fixed inc;

	std::cout << "inc       = " << inc << std::endl;
	std::cout << "++inc     = " << ++inc << std::endl;
	std::cout << "inc       = " << inc << std::endl;
	std::cout << "inc++     = " << inc++ << std::endl;
	std::cout << "inc       = " << inc << std::endl;
	std::cout << "--inc     = " << --inc << std::endl;
	std::cout << "inc--     = " << inc-- << std::endl;
	std::cout << "inc       = " << inc << std::endl;

	std::cout << std::endl;

	std::cout << "===== MIN / MAX =====" << std::endl;
	Fixed m1(3.14f);
	Fixed m2(42);

	std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	std::cout << std::endl;

	std::cout << "===== CONST MIN / MAX =====" << std::endl;
	const Fixed cm1(1.1f);
	const Fixed cm2(2.2f);

	std::cout << "min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;

	std::cout << std::endl;

	std::cout << "===== RAW BITS =====" << std::endl;
	Fixed raw;
	raw.setRawBits(256);
	std::cout << "raw bits: " << raw.getRawBits() << std::endl;
	std::cout << "raw value: " << raw << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW
	<< "============================" << std::endl
	<< "|       END OF TESTS       |" << std::endl
	<< "============================" << RESET << std::endl;

	return 0;
}