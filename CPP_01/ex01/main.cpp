/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:11:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << std::endl
			  << "======== Let's wake up from a long sleep ========"
			  << std::endl << std::endl;

	Zombie *zombieH = zombieHorde(5, "Zumbileu");

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		zombieH[i].announce();

	std::cout << std::endl << std::endl
			  << "==== and return to the great sleep of beauty ===="
			  << std::endl << std::endl;

	delete[] zombieH;

	return 0;
}
