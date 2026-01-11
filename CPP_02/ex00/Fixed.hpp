/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:34:57 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 15:34:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);

		int  getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

#endif