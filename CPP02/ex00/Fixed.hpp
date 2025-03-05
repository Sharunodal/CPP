/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:33 by arissane          #+#    #+#             */
/*   Updated: 2025/03/05 09:32:12 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int			fixedPoint;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed( const Fixed &value );
		Fixed &operator = ( const Fixed &value );
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
