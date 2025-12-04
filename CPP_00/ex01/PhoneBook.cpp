/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/04 17:12:11 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->nextIndex = 0;
}

Contact& PhoneBook::getContact(int index)
{
	return (this->contactList[index]);
}

void	PhoneBook::addContact(void)
{
	Contact newContact;

	if (!newContact.setContact())
	{
		std::cout << "\033[33mPhoneBook ~>\033[0m Contact addition cancelled.\n";
		return;
	}
	this->contactList[this->nextIndex] = newContact;

	if (this->count < 8)
		this->count++;
	this->nextIndex = (this->nextIndex + 1) % 8;
}

static std::string	formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::searchContact() const
{
	std::cout << "\n---------------------------------------------\n";
	std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < this->count; i++)
	{
		std::cout	<< "|" << "         "
					<< GREEN << i << RESET << "|"
					<< formatField(this->contactList[i].getFirstName()) << "|"
					<< formatField(this->contactList[i].getLastName())  << "|"
					<< formatField(this->contactList[i].getNickName())  << "|\n";
	}

	std::cout << "---------------------------------------------\n\n";
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= this->count)
	{
		std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Invalid index\n";
		return;
	}

	std::cout << "First Name: "   << this->contactList[index].getFirstName()    << "\n";
	std::cout << "Last Name: "    << this->contactList[index].getLastName()     << "\n";
	std::cout << "Nickname: "     << this->contactList[index].getNickName()     << "\n";
	std::cout << "Phone Number: " << this->contactList[index].getPhoneNumber()  << "\n";
	std::cout << "Secret: "       << this->contactList[index].getDarkestSecret()<< "\n";
}