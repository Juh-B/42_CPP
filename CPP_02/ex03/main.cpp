/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/14 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point outside(10, 10);
	Point edge(5, 0);
	Point vertex(0, 0);

	std::cout << "Inside:  " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Edge:    " << bsp(a, b, c, edge) << std::endl;
	std::cout << "Vertex:  " << bsp(a, b, c, vertex) << std::endl;

	return 0;
}
