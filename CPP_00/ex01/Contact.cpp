#include <iostram>
#include "Contact.hpp"

void Contact::setFirstName()
{
	std::string str;
	bool onlyAlpha = true;

	do
	{
		std::cout << "First Name: ";
		getline(std::cin, str);
		if (str.empty())
		{
			std::cout << "> [PhoneBook]: First Name can't be blank\n";
			continue;
		}
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (!isalpha(str[i]))
			{
				onlyAlpha = false;
				break;
			}
		}
		if (!onlyAlpha)
		{
			std::cout << "> [PhoneBook]: First Name must contain only alphabetic characters\n";
			onlyAlpha = true;
			continue;
		}
		this->_firstName = str;
		break;
	}
	while (true);
}
