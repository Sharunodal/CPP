/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:54:46 by arissane          #+#    #+#             */
/*   Updated: 2025/02/13 10:09:08 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie *heap_zombie;

	heap_zombie = newZombie( "Heap Zombie" );
	if ( !heap_zombie )
	{
		std::cerr << "Failed to create the Heap Zombie" << std::endl;
		return ( 1 );
	}
	heap_zombie->announce();
	std::cout << "Initiating manual delete" << std::endl;
	delete ( heap_zombie );
	randomChump( "Stack Zombie" );
	return ( 0 );
}
