/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:32:35 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/26 12:12:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;

	data.id = 42;
	data.name = "Astronalt";

	std::cout << std::endl << std::endl;

	Data* originalPtr = &data;
	std::cout << "Original pointer: " << originalPtr << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* newPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << newPtr << std::endl;

	if (originalPtr == newPtr)
		std::cout << "Pointers are equal!" << std::endl;
	else
		std::cout << "Pointers are NOT equal!" << std::endl;

	std::cout << std::endl << "Data content:" << std::endl;
	std::cout << newPtr->id << std::endl;
	std::cout << newPtr->name << std::endl;

	std::cout << std::endl << std::endl;

	return (0);
}
