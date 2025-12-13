/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:08:58 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define GREEN   "\033[32m"
# define RESET   "\033[0m"

class Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie(void);

		void announce(void) const;

	private:
		std::string		_name;
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif
