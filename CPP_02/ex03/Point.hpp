/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:39:33 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 15:39:34 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif