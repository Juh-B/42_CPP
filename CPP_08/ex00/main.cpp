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

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define GREEN	"\033[32m"
#define RESET	"\033[0m"

int main(void)
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|          VECTOR           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	try
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found in vector: " << *it << std::endl;

		easyfind(vec, 99);
	}
	catch (const std::exception& e)
	{
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|           LIST            |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	try
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);

		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found in list: " << *it << std::endl;

		easyfind(lst, 42);
	}
	catch (const std::exception& e)
	{
		std::cout << "List error: " << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|           DEQUE           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	try
	{
		std::deque<int> deq;
		deq.push_back(5);
		deq.push_back(6);
		deq.push_back(7);

		std::deque<int>::iterator it = easyfind(deq, 7);
		std::cout << "Found in deque: " << *it << std::endl;

		easyfind(deq, -1); // should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Deque error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

    return 0;
}

