/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:19:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

# define GREEN	"\033[32m"
# define RESET	"\033[0m"

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << std::endl;

	std::cout << GREEN << "====== Memory addresses: ======" << RESET << std::endl;
	std::cout << "This is the memory address of \033[34mbrain\033[0m: " << &brain << std::endl;
	std::cout << "This is the address held by \033[34mthe pointer\033[0m: " << stringPTR << std::endl;
	std::cout << "This is the address held by \033[34mthe reference\033[0m: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "====== Values: ======" << RESET << std::endl;
	std::cout << "This is the value of \033[34mbrain\033[0m: " << brain << std::endl;
	std::cout << "This is the value pointed by \033[34mthe pointer\033[0m: " << *stringPTR << std::endl;
	std::cout << "This is the value pointed by \033[34mthe reference\033[0m: " << stringREF << std::endl;

	return 0;
}
