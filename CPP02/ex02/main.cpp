/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:21:52 by arissane          #+#    #+#             */
/*   Updated: 2025/03/05 12:26:24 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\nExtra tests:" << std::endl;
	Fixed	c( Fixed( 10 ) - Fixed( 9.5f ) );
	std::cout << "c = int 10 - float 9.5 = " << c << std::endl;
	Fixed	d( Fixed( 5 ) / c );
	std::cout << "d = int 5 / c = " << d << std::endl;
	Fixed	e( c + d );
	std::cout << "e = c + d = " << e << std::endl;

	return 0;
}
