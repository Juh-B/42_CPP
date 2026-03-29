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
#include <list>
#include "MutantStack.hpp"

#define GREEN	"\033[32m"
#define RESET	"\033[0m"

int main()
{
	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|        Mutant Stack       |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

	std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Top number: " << mstack.top() << std::endl;

    mstack.pop();

	std::cout	<< std::endl << GREEN
				<< "============ POP ============"
				<< RESET << std::endl;

    std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top number: " << mstack.top() << std::endl;


	std::cout	<< std::endl << GREEN
				<< "========== ++ & -- =========="
				<< RESET << std::endl;


	mstack.push(3);
	mstack.push(10);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Mstack[0]: " << *it << std::endl;
	++it;
	std::cout << "++ Mstack[1]: " << *it << std::endl;
	--it;
	std::cout << "-- Mstack[0]: " << *it << std::endl;


	std::cout	<< std::endl << GREEN
				<< "=========== Loop ============"
				<< RESET << std::endl;

	it = mstack.begin();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);


	std::cout << std::endl << GREEN
	<< "=============================" << std::endl
	<< "|            List           |" << std::endl
	<< "=============================" << RESET
	<< std::endl << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	lst.pop_back();

	lst.push_back(3);
	lst.push_back(10);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}


	std::cout << std::endl;
    return 0;
}
