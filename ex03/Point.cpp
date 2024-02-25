/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 20:07:29 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

		Point::Point(void): x(0), y(0)
{
}

		Point::Point(float const x, float const y): x(x), y(y)
{
}

		Point::Point(Fixed const &x, Fixed const &y): x(x), y(y)
{
}

		Point::Point(Point const &point)
{
	*this = point;
}

		Point::~Point(void)
{
}

Fixed	Point::dot(Point const &point)
{
	return (this->x * point.x + this->y * point.y);
}

Fixed	Point::det(Point const &point)
{
	return (this->x * point.y - this->y * point.x);
}

Point	&Point::operator=(Point const &point)
{
	(Fixed)this->x = point.x;
	(Fixed)this->y = point.y;
	return (*this);
}

Point	Point::operator+(Point const &point) const
{
	return (Point(this->x + point.x, this->y + point.y));
}

Point	Point::operator-(Point const &point) const
{
	return (Point(this->x - point.x, this->y - point.y));
}

Point	Point::operator*(Point const &point) const
{
	return (Point(this->x * point.x, this->y * point.y));
}

Point	Point::operator/(Point const &point) const
{
	return (Point(this->x / point.x, this->y / point.y));
}
