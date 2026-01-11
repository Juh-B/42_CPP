/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:07:43 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:25:54 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << std::endl
			  << "====================== HEAP ======================"
			  << std::endl << std::endl;

	Zombie *heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie;


	std::cout << std::endl << std::endl
			  << "===================== STACK ======================"
			  << std::endl << std::endl;

	randomChump("Stacky");

	return 0;
}
