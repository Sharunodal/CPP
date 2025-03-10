/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:24:07 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 09:55:19 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define BLUE "\033[1;36m"

class ScavTrap: public ClapTrap
{
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
