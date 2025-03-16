/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:43:48 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:48:19 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog class default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const std::string& customType) : Animal(customType)
{
	std::cout << "Dog class parameterized constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& source) : Animal(source)
{
	std::cout << "Dog class copy constructor called" << std::endl;
	this->_brain = new Brain(*source._brain);
}

Dog::~Dog()
{
	std::cout << "Dog class deconstructor called" << std::endl;
	delete this->_brain;
}

Dog&	Dog::operator = (const Dog& source)
{
	std::cout << "Dog class assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator = (source);
		if (this->_brain != nullptr)
		{
			delete this->_brain;
			this->_brain = nullptr;
		}
		this->_brain = new Brain(*source._brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

Brain*	Dog::getBrain()
{
	return this->_brain;
}
