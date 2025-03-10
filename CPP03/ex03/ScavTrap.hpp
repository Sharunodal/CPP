/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:24:07 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 15:24:49 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define BLUE "\033[1;36m"

class ScavTrap: virtual public ClapTrap
{
	protected:
		static const unsigned int	_default_hitPoints;
		static const unsigned int	_default_energyPoints;
		static const unsigned int	_default_attackDamage;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad);
		ScavTrap(const ScavTrap& source);
		~ScavTrap();

		ScavTrap&	operator = (const ScavTrap& source);

		void attack(const std::string& target) override;
		void guardGate();
};

#endif
