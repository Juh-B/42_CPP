/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:12:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
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
