// #include <iostream>
// #include <cstdlib>
#include "Contact.hpp"

bool Contact::setFirstName()
{
	std::string str;
	bool onlyAlpha = true;

	do
	{
		std::cout << BLUE << "First Name: " << RESET;
		if (!getline(std::cin, str))
		{
			std::cin.clear();
			std::cout << RED << "\nInput cancelled.\n" << RESET;
			return false;
		}
		if (str.empty())
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, First Name can't be blank\n";
			continue;
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isalpha(str[i]))
			{
				onlyAlpha = false;
				break;
			}
		}
		if (!onlyAlpha)
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, First Name must contain only alphabetic characters\n";
			onlyAlpha = true;
			continue;
		}
		this->_firstName = str;
		return true;
	}
	while (true);
}

bool Contact::setLastName()
{
	std::string str;
	bool onlyAlpha = true;

	do
	{
		std::cout << BLUE << "Last Name: " << RESET;
		if (!getline(std::cin, str))
		{
			std::cin.clear();
			std::cout << RED << "\nInput cancelled.\n" << RESET;
			return false;
		}
		if (str.empty())
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Last Name can't be blank\n";
			continue;
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isalpha(str[i]))
			{
				onlyAlpha = false;
				break;
			}
		}
		if (!onlyAlpha)
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Last Name must contain only alphabetic characters\n";
			onlyAlpha = true;
			continue;
		}
		this->_lastName = str;
		return true;
	}
	while (true);
}

bool Contact::setNickName()
{
	std::string str;

	do
	{
		std::cout << BLUE << "Nick Name: " << RESET;
		if (!getline(std::cin, str))
		{
			std::cin.clear();
			std::cout << RED << "\nInput cancelled.\n" << RESET;
			return false;
		}
		if (str.empty())
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Nick Name can't be blank\n";
			continue;
		}
		this->_nickName = str;
		return true;
	}
	while (true);
}

bool Contact::setPhoneNumber()
{
	std::string str;
	bool onlyDigit = true;

	do
	{
		std::cout << BLUE << "Phone Number: " << RESET;
		if (!getline(std::cin, str))
		{
			std::cin.clear();
			std::cout << RED << "\nInput cancelled.\n" << RESET;
			return false;
		}
		if (str.empty())
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Phone number can't be blank\n";
			continue;
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
			{
				onlyDigit = false;
				break;
			}
		}
		if (!onlyDigit)
		{
			onlyDigit = true;
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Phone number must contain only numeric characters\n";
			continue;;
		}
		this->_phoneNumber = str;
		return true;
	}
	while (true);
}

bool Contact::setDarkestSecret()
{
	std::string str;

	do
	{
		std::cout << BLUE << "Darkest Secret: " << RESET;
		if (!getline(std::cin, str))
		{
			std::cin.clear();
			std::cout << RED << "\nInput cancelled.\n" << RESET;
			return false;
		}
		if (str.empty())
		{
			std::cout << "\033[33mPhoneBook ~>\033[0m Whoops, Darkest Secret can't be blank\n";
			continue;
		}
		this->_darkestSecret = str;
		return true;
	}
	while (true);
}

bool Contact::setContact() {
    if (!setFirstName()) return false;
    if (!setLastName()) return false;
    if (!setNickName()) return false;
    if (!setPhoneNumber()) return false;
    if (!setDarkestSecret()) return false;

    std::cout << "\033[32mPhoneBook ~>\033[0m New contact added!\n";
	return (true);
}

const std::string& Contact::getFirstName() const {return (this->_firstName);}
const std::string& Contact::getLastName() const {return (this->_lastName);}
const std::string& Contact::getNickName() const {return (this->_nickName);}
const std::string& Contact::getPhoneNumber() const {return (this->_phoneNumber);}
const std::string& Contact::getDarkestSecret() const {return (this->_darkestSecret);}
