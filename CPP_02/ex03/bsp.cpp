/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/14 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed cross(Point const &a, Point const &b, Point const &p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
		 - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab = cross(a, b, point);
	Fixed bc = cross(b, c, point);
	Fixed ca = cross(c, a, point);

	if (ab == 0 || bc == 0 || ca == 0)
		return false;

	bool has_neg = (ab < 0) || (bc < 0) || (ca < 0);
	bool has_pos = (ab > 0) || (bc > 0) || (ca > 0);

	return !(has_neg && has_pos);
}
