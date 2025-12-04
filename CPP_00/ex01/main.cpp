/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/04 17:10:22 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook pbook;
	std::string command;

	std::cout << "----------------------------------------------\n";
	std::cout << "|                 \033[32mPhone Book\033[0m                 |\n";
	std::cout << "----------------------------------------------\n";

	while (true)
	{
		std::cout << "\n\033[32mPhoneBook ~>\033[0m ADD | SEARCH | EXIT\n";

		if (!getline(std::cin, command))
			break;

		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			pbook.addContact();
		}
		else if (command == "SEARCH")
		{
			pbook.searchContact();

			std::cout << "\033[32mEnter index number to view details:\033[0m ";
			std::string input;
			if (!getline(std::cin, input))
				break;
			if (input.empty())
				continue;

			int index = atoi(input.c_str());
			pbook.displayContact(index);
		}
		else
		{
			std::cout << "\033[31mPhoneBook ~>\033[0m Invalid command.\n";
			std::cout << "\033[33mPhoneBook ~>\033[0m Please, use ADD, SEARCH or EXIT.\n";
		}
	}

	std::cout << "----------------------------------------------\n";
	std::cout << "|                  \033[33mGoodBye\033[0m                   |\n";
	std::cout << "----------------------------------------------\n";

	return 0;
}