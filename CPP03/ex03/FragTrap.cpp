/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:41:45 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 15:24:33 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const unsigned int	FragTrap::_default_hitPoints = 100;
const unsigned int	FragTrap::_default_energyPoints = 100;
const unsigned int	FragTrap::_default_attackDamage = 30;

FragTrap::FragTrap() : ClapTrap("FragTrap", _default_hitPoints, _default_energyPoints, _default_attackDamage)
{
	std::cout << "FragTrap; Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, _default_hitPoints, _default_energyPoints, _default_attackDamage)
{
	std::cout << "FragTrap; Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << "FragTrap; Custom parameter constructor called"
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source)
{
	std::cout << "FragTrap; Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap; Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& source)
{
	if (this != &source)
		ClapTrap::operator = (source);
	std::cout << "FragTrap; Copy assignment operator called" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap " << _name
	<< " shouts \"High fives, guys! High fives!\""
	<< DEFAULT << std::endl;
}
