/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:12:40 by arissane          #+#    #+#             */
/*   Updated: 2025/03/08 13:53:58 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap; Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap; Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad) : _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
	std::cout << "ClapTrap; Custom parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) : _name(source._name), _hitPoints(source._hitPoints), _energyPoints(source._energyPoints), _attackDamage(source._attackDamage)
{
	std::cout << "ClapTrap; Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap; Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& source)
{
	if (this != &source)
	{
		_name = source._name;
		_hitPoints = source._hitPoints;
		_energyPoints = source._energyPoints;
		_attackDamage = source._attackDamage;
	}
	std::cout << "ClapTrap; Copy assignment operator called" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << PURPLE << "ClapTrap " << this->_name
		<< " is out of HP and can't attack"
		<< DEFAULT << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << PURPLE << "ClapTrap " << this->_name 
		<< " is out of EP and can't attack"
		<< DEFAULT << std::endl;
	}
	else
	{
		_energyPoints -= 1;
		std::cout << PURPLE << "ClapTrap " << this->_name << " attacks "
		<< target << " causing " << this->_attackDamage
		<< " points of damage!"
		<< DEFAULT << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << PURPLE << "ClapTrap " << _name << " took " << amount
	<< " points of damage"
	<< DEFAULT << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << PURPLE << "ClapTrap " << _name
		<< " is out of HP and can no longer be repaired"
		<< DEFAULT << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << PURPLE << "ClapTrap " << _name
		<< " is out of EP and can no longer repair itself"
		<< DEFAULT << std::endl;
	}
	else
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << PURPLE << "ClapTrap " << _name << " was repaired for "
		<< amount << " HP"
		<< DEFAULT << std::endl;
	}
}

void	ClapTrap::printStats()
{
	std::cout << "ClapTrap " << _name << " HP = " << _hitPoints
		<< " EP = " << _energyPoints << " AD = " << _attackDamage
		<< std::endl;
}

void	ClapTrap::setName(const std::string& name)
{
	std::cout << "ClapTrap " << _name << " name changed to " << name
		<< std::endl;
	_name = name;
}
