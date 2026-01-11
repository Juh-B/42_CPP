/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:30:09 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:30:10 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define GREEN   "\033[32m"
# define BLUE   "\033[34m"
# define RESET   "\033[0m"

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void announce(void) const;
		void setName(const std::string& name);

	private:
		std::string		_name;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif