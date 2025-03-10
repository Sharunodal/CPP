/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:29:40 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 15:25:15 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const unsigned int	ScavTrap::_default_hitPoints = 100;
const unsigned int	ScavTrap::_default_energyPoints = 50;
const unsigned int	ScavTrap::_default_attackDamage = 20;

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", _default_hitPoints, _default_energyPoints, _default_attackDamage)
{
	std::cout << "ScavTrap; Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, _default_hitPoints, _default_energyPoints, _default_attackDamage)
{
	std::cout << "ScavTrap; Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << "ScavTrap; Custom parameter constructor called"
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source)
{
	std::cout << "ScavTrap; Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap; Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& source)
{
	if (this != &source)
		ClapTrap::operator = (source);
	std::cout << "ScavTrap; Copy assignment operator called" << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << BLUE << "ScavTrap " << _name
		<< " is out of HP and can't attack"
		<< DEFAULT << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << BLUE << "ScavTrap " << _name 
		<< " is out of EP and can't attack"
		<< DEFAULT << std::endl;
	}
	else
	{
		_energyPoints -= 1;
		std::cout << BLUE << "ScavTrap " << _name << " attacks "
		<< target << " causing " << _attackDamage
		<< " points of damage!"
		<< DEFAULT << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << _name
		<< " is now in Gate keeper mode"
		<< DEFAULT << std::endl;
}
