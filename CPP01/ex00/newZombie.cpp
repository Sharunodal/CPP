/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:22:38 by arissane          #+#    #+#             */
/*   Updated: 2025/02/13 10:16:51 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie( std::string name )
{
	try
	{
		Zombie *z = new Zombie( name );
		return ( z );
	}
	catch (const std::bad_alloc& error)
	{
		std::cerr << "Allocation failure" << error.what() << std::endl;
		return ( 0 );
	}
}
