/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:24:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:22:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define WHITE_B	"\033[1;37m"
# define GREEN	"\033[32m"
# define RESET	"\033[0m"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);

		std::string getType() const;
		virtual void makeSound() const = 0;

	protected:
		std::string type;
};

#endif
