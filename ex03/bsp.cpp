/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 20:11:13 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "Point.hpp"

static bool	_is_left_of_edge(Point const &a, Point const &b, Point const &point)
{
	Point	edgeA(point - a);
	Point	edgeB(point - b);

	return (Fixed(0) < edgeA.det(edgeB));
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (!_is_left_of_edge(a, b, point))
		return (false);
	if (!_is_left_of_edge(b, c, point))
		return (false);
	if (!_is_left_of_edge(c, a, point))
		return (false);
	return (true);
}
