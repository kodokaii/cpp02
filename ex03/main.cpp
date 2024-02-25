/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 20:11:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
	Point	a(1, -1);
	Point	b(0, 1);
	Point	c(-1, -1);
	float	x(0);
	float	y(0);

	if (1 < argc)
		x = std::atof(argv[1]);
	if (2 < argc)
		y = std::atof(argv[2]);
	std::cout << "bsp = " << bsp(a, b, c, Point(x, y)) << std::endl;

	return 0;
}
