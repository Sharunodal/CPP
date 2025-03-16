/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:43:48 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 11:59:10 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog class default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const std::string& customType) : Animal(customType)
{
	std::cout << "Dog class parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source)
{
	std::cout << "Dog class copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog class deconstructor called" << std::endl;
}

Dog&	Dog::operator = (const Dog& source)
{
	std::cout << "Dog class assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator = (source);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}
