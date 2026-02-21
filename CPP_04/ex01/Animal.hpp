/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:31:50 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 18:34:37 by jcosta-b         ###   ########.fr       */
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
		virtual void makeSound() const;

	protected:
		std::string type;
};

#endif