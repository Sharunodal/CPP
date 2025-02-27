/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:12:23 by arissane          #+#    #+#             */
/*   Updated: 2025/02/27 14:04:20 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number ) : fixedPointValue( number << fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float number ) : fixedPointValue( roundf( number * ( 1 << fractionalBits ))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& newValue ) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = newValue.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = ( const Fixed& newValue ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &newValue )
		fixedPointValue = newValue.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& newValue) const {
	if (this->fixedPointValue > newValue.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed& newValue) const {
	if (this->fixedPointValue < newValue.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& newValue) const {
	if (this->fixedPointValue >= newValue.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& newValue) const {
	if (this->fixedPointValue <= newValue.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed& newValue) const {
	if (this->fixedPointValue == newValue.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& newValue) const {
	if (this->fixedPointValue != newValue.fixedPointValue)
		return true;
	else
		return false;
}

Fixed&	Fixed::operator + (const Fixed& newValue) {
	int	a = this->getRawBits();
	int	b = newValue.getRawBits();

	this->setRawBits( a + b );
	return *this;
}

Fixed&	Fixed::operator - (const Fixed& newValue) {
	int	a = this->getRawBits();
	int	b = newValue.getRawBits();

	this->setRawBits( a - b );
	return *this;
}

Fixed&	Fixed::operator * (const Fixed& newValue) {
	int	a = this->getRawBits();
	int	b = newValue.getRawBits();

	this->setRawBits( ( a * b ) >> fractionalBits );
	return *this;
}

Fixed&	Fixed::operator / (const Fixed& newValue) {
	int	a = this->getRawBits();
	int	b = newValue.getRawBits();

	this->setRawBits( ( a / b ) >> fractionalBits );
	return *this;
}

Fixed&	Fixed::operator ++ () {
	this->fixedPointValue += 1;
	return *this;
}

Fixed&	Fixed::operator -- () {
	this->fixedPointValue -= 1;
	return *this;
}

Fixed	Fixed::operator ++ ( int ) {
	Fixed	fixed = *this;
	this->fixedPointValue += 1;
	return fixed;
}

Fixed	Fixed::operator -- ( int ) {
	Fixed	fixed = *this;
	this->fixedPointValue -= 1;
	return fixed;
}

Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	else
		return b;
}

Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	else
		return b;
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	else
		return b;
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	else
		return b;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}

int	Fixed::toInt( void ) const {
	return ( this->fixedPointValue >> fractionalBits );
}

float	Fixed::toFloat( void ) const {
	float	intToFloat = this->fixedPointValue;

	return ( intToFloat / ( 1 << fractionalBits ) );
}

std::ostream&	operator<<( std::ostream& outputStream, const Fixed& fixed ) {
	outputStream << fixed.toFloat();
	return outputStream;
}
