/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:39:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 15:39:26 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                            Orthodox Canonical Form                         */
/* ************************************************************************** */

Point::Point() :
		_x(0), _y(0)
{}

Point::Point(float const x, float const y) :
		 _x(x), _y(y)
{}

Point::Point(const Point &other) :
		_x(other._x), _y(other._y)
{}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}


/* ************************************************************************** */
/*                          Getters / Setters                                 */
/* ************************************************************************** */

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }