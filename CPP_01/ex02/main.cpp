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

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "====== Memory addresses: ======" << std::endl;
	std::cout << "This is the memory address of brain: " << &brain << std::endl;
	std::cout << "This is the address held by the pointer: " << stringPTR << std::endl;
	std::cout << "This is the address held by the reference: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "====== Values: ======" << std::endl;
	std::cout << "This is the value of brain: " << brain << std::endl;
	std::cout << "This is the value pointed to by the pointer: " << *stringPTR << std::endl;
	std::cout << "This is the value pointed to by the reference: " << stringREF << std::endl;

	return 0;
}
