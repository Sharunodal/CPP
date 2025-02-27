/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:40:57 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 10:23:22 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	int	i = 0;

	if ( N < 1 )
		return ( NULL );
	try
	{
		Zombie	*horde = new Zombie[N];
		while ( i < N )
		{
			horde[i].giveName( name );
			i++;
		}
		return ( horde );
	}
	catch (const std::bad_alloc& error)
	{
		std::cerr << "Allocation failure: " << error.what() << std::endl;
		return ( 0 );
	}
}
