/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:41:42 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 09:54:55 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define GREEN "\033[1;32m"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad);
		FragTrap(const FragTrap& source);
		~FragTrap();

		FragTrap&	operator = (const FragTrap& source);

		void highFivesGuys(void);
};

#endif
