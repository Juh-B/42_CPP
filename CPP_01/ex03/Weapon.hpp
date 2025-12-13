/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

# define GREEN   "\033[32m"
# define BLUE   "\033[34m"
# define RESET   "\033[0m"

class Weapon
{
	public:
		Weapon(const std::string& type);
		~Weapon(void);

		const	std::string& getType(void) const;
		void	setType(const std::string& type);

	private:
		std::string		_type;
};

#endif
