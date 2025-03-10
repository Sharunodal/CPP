/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:13:01 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 10:30:04 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define PURPLE "\033[1;35m"
# define RED "\033[1;31m"
# define DEFAULT "\033[0;0m"

class ClapTrap {
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad);
		ClapTrap(const ClapTrap& source);
		~ClapTrap();

		ClapTrap&	operator = (const ClapTrap& source);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStats();
		void setName(const std::string& name);
};

#endif
