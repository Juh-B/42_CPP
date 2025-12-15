/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/14 12:12:56 by jcosta-b         ###   ########.fr       */
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
