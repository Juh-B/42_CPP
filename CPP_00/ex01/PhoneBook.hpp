/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/04 17:33:22 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
		int count;
		int nextIndex;

	public:
		PhoneBook();

		void addContact();
		void searchContact() const;
		void displayContact(int index) const;

		Contact& getContact(int index);
};

#endif