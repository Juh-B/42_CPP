/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/14 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const Fixed& other)
{	*this = other; }

Fixed::Fixed(int const n)
{    _rawBits = n << _fractionalBits; }

Fixed::Fixed(float const f)
{    _rawBits = roundf(f * (1 << _fractionalBits)); }

Fixed::~Fixed(void) {}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_rawBits = other._rawBits;

	return *this;
}


/* ************************************************************************** */
/*                         Comparison operators                               */
/* ************************************************************************** */

bool Fixed::operator>(const Fixed &other) const
{	return _rawBits > other._rawBits; }

bool Fixed::operator<(const Fixed &other) const
{	return _rawBits < other._rawBits; }

bool Fixed::operator>=(const Fixed &other) const
{	return _rawBits >= other._rawBits; }

bool Fixed::operator<=(const Fixed &other) const
{	return _rawBits <= other._rawBits; }

bool Fixed::operator==(const Fixed &other) const
{	return _rawBits == other._rawBits; }

bool Fixed::operator!=(const Fixed &other) const
{	return _rawBits != other._rawBits; }


/* ************************************************************************** */
/*                         Arithmetic operators                               */
/* ************************************************************************** */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result._rawBits = _rawBits + other._rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result._rawBits = _rawBits - other._rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	long tmp = (long)_rawBits * (long)other._rawBits;
	result._rawBits = tmp >> _fractionalBits;

	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	long tmp = ((long)_rawBits << _fractionalBits) / other._rawBits;
	result._rawBits = tmp;

	return result;
}


/* ************************************************************************** */
/*                         Increment / Decrement                              */
/* ************************************************************************** */

Fixed &Fixed::operator++()
{
	_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	_rawBits += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	_rawBits -= 1;
	return temp;
}


/* ************************************************************************** */
/*                                Min / Max                                   */
/* ************************************************************************** */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{	return (a < b ? a : b);	}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{	return (a < b ? a : b);	}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{	return (a > b ? a : b);	}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{	return (a > b ? a : b);	}


/* ************************************************************************** */
/*                              Conversions                                   */
/* ************************************************************************** */

float Fixed::toFloat(void) const
{	return (float)_rawBits / (1 << _fractionalBits); }

int Fixed::toInt(void) const
{	return _rawBits >> _fractionalBits; }


/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}


/* ************************************************************************** */
/*                         Operator overload                                  */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return out;
}
