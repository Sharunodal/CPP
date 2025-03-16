/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:29:22 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 12:02:43 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal class default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& customType) : type(customType)
{
	std::cout << "WrongAnimal class parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) : type(source.type)
{
	std::cout << "WrongAnimal class copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal class deconstructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& source)
{
	std::cout << "WrongAnimal class assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "..?" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
