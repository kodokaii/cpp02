/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/02/25 13:33:58 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cmath>
# include <iostream>

# define	FRACTIONAL_BITS	8;

class Fixed
{
	private:
		int					rawBits;
		static int const	fractBits = FRACTIONAL_BITS;

	public:
				Fixed(void);
				Fixed(int const n);
				Fixed(float const f);
				Fixed(Fixed const &fixed);
				~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(Fixed const &fixed);
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed);

#endif
