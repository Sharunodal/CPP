/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:33 by arissane          #+#    #+#             */
/*   Updated: 2025/02/27 12:08:55 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed
{
	private:
		int			fixedPoint;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed( const int number );
		Fixed( const float number );
		Fixed( const Fixed &value );
		~Fixed();

		Fixed& operator = ( const Fixed& value );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int	toInt() const;
};

std::ostream&	operator<<( std::ostream& outputStream, const Fixed& fixed );

#endif
