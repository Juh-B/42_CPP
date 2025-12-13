/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:07:21 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/06 17:09:56 by jcosta-b         ###   ########.fr       */
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
