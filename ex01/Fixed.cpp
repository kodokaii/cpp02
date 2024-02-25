/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 13:34:27 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

		Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

		Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = n << Fixed::fractBits;
}

		Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(f * float(1 << Fixed::fractBits));
}
		Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
		Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float(this->rawBits) / float(1 << Fixed::fractBits));
}

int		Fixed::toInt(void) const
{
	return (this->rawBits >> Fixed::fractBits);
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
