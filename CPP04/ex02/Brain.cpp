/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:46:05 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:32:28 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain class default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "Default idea";
	}
}

Brain::Brain(const Brain& source)
{
	std::cout << "Brain class copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = source.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain class deconstructor called" << std::endl;
}

Brain&	Brain::operator = (const Brain& source)
{
	std::cout << "Brain class assignment operator called" << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = source.ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea(int index, std::string newIdea)
{
	if (index < 0 || index > 99)
	{
		return ;
	}
	this->ideas[index] = newIdea;
}

void	Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
	{
		return ;
	}
	std::cout << this->ideas[index] << std::endl;
}
