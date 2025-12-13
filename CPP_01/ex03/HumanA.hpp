/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

# define GREEN   "\033[32m"
# define BLUE   "\033[34m"
# define RESET   "\033[0m"

class Weapon;

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);

		void attack(void) const;

	private:
		std::string		_name;
		Weapon&			_weapon;
};

#endif
