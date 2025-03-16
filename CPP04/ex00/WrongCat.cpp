/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:37:21 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 12:04:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat class default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const std::string& customType) : WrongAnimal(customType)
{
	std::cout << "WrongCat class parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source)
{
	std::cout << "WrongCat class copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat class deconstructor called" << std::endl;
}

WrongCat&	WrongCat::operator = (const WrongCat& source)
{
	std::cout << "WrongCat class assignment operator called" << std::endl;
	if (this != &source)
	{
		WrongAnimal::operator = (source);
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}
