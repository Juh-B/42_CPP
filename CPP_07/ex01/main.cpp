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
#include "iter.hpp"

#define GREEN	"\033[32m"
#define RESET	"\033[0m"

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void printConst(const T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void addOne(T &x)
{
	x++;
}

int main()
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|      Not Const Array      |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	int arr[] = {1,2,3,4,5};
	int len = 5;

	std::cout << GREEN
			<< "===== Print Array ====="
			<< RESET << std::endl;
	iter(arr, len, print);

	std::cout << std::endl << GREEN
			<< "===== Add one & Print ====="
			<< RESET << std::endl;

	iter(arr, len, addOne);
	iter(arr, len, print);

	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|      Const Array          |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	const int constArr[] = {10,20,30,40,50};

	std::cout << GREEN
              << "===== Print Array ====="
              << RESET << std::endl;

    iter(constArr, 5, printConst);

	std::cout << std::endl;

	return 0;
}
