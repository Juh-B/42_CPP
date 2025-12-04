/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/04 17:10:15 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
#include <iostream>
#include <cstdlib>

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define RESET   "\033[0m"

class Contact
{
	public:
		bool setContact(void);

		bool setFirstName(void);
		bool setLastName(void);
		bool setNickName(void);
		bool setPhoneNumber(void);
		bool setDarkestSecret(void);

		const std::string& getFirstName(void) const;
		const std::string& getLastName(void) const;
		const std::string& getNickName(void) const;
		const std::string& getPhoneNumber(void) const;
		const std::string& getDarkestSecret(void) const;

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
};

#endif