/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:15:33 by arissane          #+#    #+#             */
/*   Updated: 2025/04/16 09:29:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

#define CYAN "\033[1;36m"
#define DEFAULT "\033[0;0m"

int	main( void )
{
	Array<int>	integers( 200 );
	int * a = new int[200];
	srand( time( NULL ) );
	for ( int i = 0; i < 200; i++ )
	{
		const int value = rand();
		integers[i] = value;
		a[i] = value;
	}
	Array<int>	operatorcopy = integers;
	Array<int>	copyconstructed(operatorcopy);

	std::cout << CYAN << "integers.size():" << DEFAULT << std::endl;
	std::cout << integers.size() << std::endl;
	std::cout << CYAN << "\nvalue at [42] in each array:" << DEFAULT << std::endl;
	std::cout << "integers[42] == " << integers[42] << std::endl;
	std::cout << "operatorcopy[42] == " << operatorcopy[42] << std::endl;
	std::cout << "copyconstructed[42] == " << copyconstructed[42] << std::endl;
	std::cout << "a[42] == " << a[42] << std::endl;
	
	std::cout << CYAN << "\nchanging integers[42] to 5:" << DEFAULT << std::endl;
	integers[42] = 5;
	std::cout << "integers[42] == " << integers[42] << std::endl;
	std::cout << "operatorcopy[42] == " << operatorcopy[42] << std::endl;
	std::cout << "copyconstructed[42] == " << copyconstructed[42] << std::endl;
	std::cout << "a[42] == " << a[42] << std::endl;

	std::cout << CYAN << "\nchanging values at integers[-1] and integers[200]:" << DEFAULT << std::endl;
	try
	{
		integers[-1] = 55;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		integers[200] = 883;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	for (int k = 0; k < 200; k++)
	{
		integers[k] = rand();
	}
	delete [] a;

	Array<std::string>	strings( 2 );
	strings[0] = "Hello";
	strings[1] = "there";

	std::cout << CYAN << "\nvalues at [0] and [1] in strings array:" << DEFAULT << std::endl;
	std::cout << "strings[0] == " << strings[0] << std::endl;
	std::cout << "strings[1] == " << strings[1] << std::endl;

	return 0;
}
