/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:03:25 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 15:16:48 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"), _name("DiamondTrap")
{
	std::cout << "DiamondTrap; Default constructor called" << std::endl;
	this->_hitPoints = FragTrap::_default_hitPoints;
	this->_energyPoints = ScavTrap::_default_energyPoints;
	this->_attackDamage = FragTrap::_default_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap; Constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source) : ClapTrap(source.ClapTrap::_name + "_clap_name"), _name(source._name)
{
	std::cout << "DiamondTrap; Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap; Destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& source)
{
	if (this != &source)
	{
		ClapTrap::operator = (source);
		this->_name = (source._name + "_clap_name");
	}
	std::cout << "DiamondTrap; Copy assignment operator called" << std::endl;
	ClapTrap::_name = source.ClapTrap::_name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW << "My name is " << _name
		<< "\nMy ClapTrap name is " << ClapTrap::_name << "\n"
		<< DEFAULT << std::endl;
}
