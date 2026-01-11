/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:35:02 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:35:03 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

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