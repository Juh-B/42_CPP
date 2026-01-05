/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:24:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:22:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define WHITE_B	"\033[1;37m"
# define GREEN_B	"\033[1;32m"
# define RED_B	"\033[1;31m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define RESET	"\033[0m"

class WrongAnimal
{
	public:
		WrongAnimal(void);
		~WrongAnimal(void);

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;
};

#endif
