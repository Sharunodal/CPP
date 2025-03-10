/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:55:40 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 15:06:11 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define YELLOW "\033[1;33m"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& source);
		~DiamondTrap();

		DiamondTrap&	operator = (const DiamondTrap& source);

		void attack(const std::string& target) override;
		void whoAmI();
};

#endif
