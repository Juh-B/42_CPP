/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>

# define GREEN   "\033[32m"
# define BLUE   "\033[34m"
# define RESET   "\033[0m"

class Weapon;

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon& weapon);

	private:
		std::string		_name;
		Weapon*			_weapon;
};

#endif
