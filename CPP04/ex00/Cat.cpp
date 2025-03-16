/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:00:24 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 11:58:40 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat class default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const std::string& customType) : Animal(customType)
{
	std::cout << "Cat class parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& source) : Animal(source)
{
	std::cout << "Cat class copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat class deconstructor called" << std::endl;
}

Cat&	Cat::operator = (const Cat& source)
{
	std::cout << "Cat class assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator = (source);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
