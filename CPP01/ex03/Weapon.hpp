/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:29:01 by arissane          #+#    #+#             */
/*   Updated: 2025/02/13 13:12:21 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		void			setType(std::string type);
		std::string const	&getType(void);
};

#endif
