/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:34:51 by arissane          #+#    #+#             */
/*   Updated: 2025/03/18 11:21:19 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal class default constructor called" << std::endl;
}

Animal::Animal(const std::string& customType) : type(customType)
{
	std::cout << "Animal class parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& source) : type(source.type)
{
	std::cout << "Animal class copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal class deconstructor called" << std::endl;
}

Animal&	Animal::operator = (const Animal& source)
{
	std::cout << "Animal class assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return *this;
}

std::string	Animal::getType() const
{
	return this->type;
}
