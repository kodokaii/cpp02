/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 20:08:01 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
				Point(void);
				Point(float const x, float const y);
				Point(Fixed const &x, Fixed const &y);
				Point(Point const &point);
				~Point(void);
		Fixed	dot(Point const &point);
		Fixed	det(Point const &point);
		Point	&operator=(Point const &point);
		Point	operator+(Point const &point) const;
		Point	operator-(Point const &point) const;
		Point	operator*(Point const &point) const;
		Point	operator/(Point const &point) const;
};

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif
