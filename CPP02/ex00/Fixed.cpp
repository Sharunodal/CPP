/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:23 by arissane          #+#    #+#             */
/*   Updated: 2025/02/27 09:27:10 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &value ) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = value.getRawBits();
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
