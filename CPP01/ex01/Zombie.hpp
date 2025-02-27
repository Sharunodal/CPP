/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:35:34 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 10:22:59 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void );
		void	giveName( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif
