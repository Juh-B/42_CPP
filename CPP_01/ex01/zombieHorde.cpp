/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:30:54 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:30:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name)
{
	if (N <= 0)
	{
		std::cout << "Please, N must be a number greater than zero!"
				  << std::endl;
		return (NULL);
	}

	Zombie* zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].setName(name);

	return (zombie);
}