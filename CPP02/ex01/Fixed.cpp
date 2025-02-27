/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:23 by arissane          #+#    #+#             */
/*   Updated: 2025/02/27 11:42:24 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number ) : fixedPoint( number << fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float number ) : fixedPoint( roundf( number * ( 1 << fractionalBits ))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &value ) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = value.getRawBits();
}

Fixed &Fixed::operator = ( const Fixed &value ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &value )
		fixedPoint = value.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}

int	Fixed::toInt( void ) const {
	return ( fixedPoint >> fractionalBits );
}

float	Fixed::toFloat( void ) const {
	float	intToFloat = fixedPoint;

	return ( intToFloat / ( 1 << fractionalBits ) );
}

std::ostream&	operator<<( std::ostream& outputStream, const Fixed& fixed ) {
	outputStream << fixed.toFloat();
	return outputStream;
}
