/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 15:46:39 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

			Fixed::Fixed(void)
{
	this->rawBits = 0;
}

			Fixed::Fixed(int const n)
{
	this->rawBits = n << Fixed::fractBits;
}

			Fixed::Fixed(float const f)
{
	this->rawBits = roundf(f * float(1 << Fixed::fractBits));
}
			Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
}
			Fixed::~Fixed(void)
{
}

int			Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void		Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float		Fixed::toFloat(void) const
{
	return (float(this->rawBits) / float(1 << Fixed::fractBits));
}

int			Fixed::toInt(void) const
{
	return (this->rawBits >> Fixed::fractBits);
}

Fixed		&Fixed::operator=(Fixed const &fixed)
{
	this->rawBits = fixed.rawBits;
	return (*this);
}

Fixed		Fixed::operator+(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = this->rawBits + fixed.rawBits;
	return (res);
}

Fixed		Fixed::operator-(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = this->rawBits - fixed.rawBits;
	return (res);
}

Fixed		Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = (long(this->rawBits) * long(fixed.rawBits)) >> Fixed::fractBits;
	return (res);
}

Fixed		Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = (long(this->rawBits) << long(Fixed::fractBits)) / fixed.rawBits;
	return (res);
}

Fixed		&Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	res(*this);

	this->rawBits++;
	return (res);
}

Fixed		&Fixed::operator--(void)
{
	this->rawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed	res(*this);

	this->rawBits--;
	return (res);
}

bool		Fixed::operator>(Fixed const &fixed) const
{
	return (this->rawBits > fixed.rawBits);
}

bool		Fixed::operator<(Fixed const &fixed) const
{
	return (this->rawBits < fixed.rawBits);
}

bool		Fixed::operator>=(Fixed const &fixed) const
{
	return (this->rawBits >= fixed.rawBits);
}

bool		Fixed::operator<=(Fixed const &fixed) const
{
	return (this->rawBits <= fixed.rawBits);
}

bool		Fixed::operator==(Fixed const &fixed) const
{
	return (this->rawBits == fixed.rawBits);
}

bool		Fixed::operator!=(Fixed const &fixed) const
{
	return (this->rawBits != fixed.rawBits);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (b);
	return (a);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
