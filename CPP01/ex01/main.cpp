/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:55:23 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 08:55:01 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*horde;
	int	N = 10;
	int	i = 0;

	horde = zombieHorde( N, "Horde" );
	if ( !horde )
	{
		std::cerr << "Failed to create Zombie Horde" << std::endl;
		return ( 1 );
	}
	while ( i < N )
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return ( 0 );
}
