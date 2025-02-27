/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:33 by arissane          #+#    #+#             */
/*   Updated: 2025/02/27 13:56:25 by arissane         ###   ########.fr       */
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
		int			fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed( const int number );
		Fixed( const float number );
		Fixed( const Fixed& newValue );
		~Fixed();

		Fixed&	operator = ( const Fixed& newValue );

		bool	operator > ( const Fixed& newValue ) const;
		bool	operator < ( const Fixed& newValue ) const;
		bool	operator >= ( const Fixed& newValue ) const;
		bool	operator <= ( const Fixed& newValue ) const;
		bool	operator == ( const Fixed& newValue ) const;
		bool	operator != ( const Fixed& newValue ) const;

		Fixed&	operator + ( const Fixed& newValue );
		Fixed&	operator - ( const Fixed& newValue );
		Fixed&	operator * ( const Fixed& newValue );
		Fixed&	operator / ( const Fixed& newValue );

		Fixed&	operator ++ ();
		Fixed&	operator -- ();
		Fixed	operator ++ ( int );
		Fixed	operator -- ( int );

		static Fixed&		min( Fixed& a, Fixed& b );
		static Fixed&		max( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int	toInt() const;
};

std::ostream&	operator<<( std::ostream& outputStream, const Fixed& fixed );

#endif
