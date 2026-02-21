/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:38:20 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:38:21 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

bool replaceFile(const std::string& filename,
				 const std::string& s1,
				 const std::string& s2);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> s1 s2" << std::endl;
		return 1;
	}

	if (!replaceFile(argv[1], argv[2], argv[3]))
	{
		std::cerr << "Error!" << std::endl;
		return 1;
	}

	return 0;
}