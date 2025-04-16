/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:48:08 by arissane          #+#    #+#             */
/*   Updated: 2025/04/14 10:59:31 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iomanip>
#define CYAN "\033[1;36m"
#define DEFAULT "\033[0;0m"

void	printInteger( int& integer )
{
	std::cout << integer << std::endl;
}

void	plusOne( int& integer )
{
	integer += 1;
}

void	minusOne( int& integer )
{
	integer -= 1;
}

void	printString( std::string& str )
{
	std::cout << str << std::endl;
}

void	addQuestionMark( std::string& str )
{
	str += "?";
}

void	printDouble( double& dbl )
{
	std::cout << std::fixed << std::setprecision(1) << dbl << std::endl;
}

void	plusPointFive( double& dbl )
{
	dbl += 0.5;
}

int	main( void )
{
	int integerArray[] = { 1, 2, 3, 4, 5 };
	std::cout << CYAN << "Use function printInteger on each element inside an integer array" << DEFAULT << std::endl;
	iter( integerArray, 5, printInteger );
	std::cout << CYAN << "\nplusOne on each element once" << DEFAULT << std::endl;
	iter( integerArray, 5, plusOne );
	iter( integerArray, 5, printInteger );
	std::cout << CYAN << "\nminusOne on each element thrice" << DEFAULT << std::endl;
	iter( integerArray, 5, minusOne );
	iter( integerArray, 5, minusOne );
	iter( integerArray, 5, minusOne );
	iter( integerArray, 5, printInteger );

	std::cout << CYAN <<"\nUse function printString on each element inside a string array" << DEFAULT << std::endl;
	std::string stringArray[] = { "this", "is", "an", "example", "array" };
	iter( stringArray, 5, printString );
	std::cout << CYAN << "\naddQuestionMark on each element" << DEFAULT << std::endl;
	iter( stringArray, 5, addQuestionMark );
	iter( stringArray, 5, printString );

	std::cout << CYAN <<"\nUse function printDouble on each element inside a double array" << DEFAULT << std::endl;
	double doubleArray[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	iter( doubleArray, 5, printDouble );
	std::cout << CYAN << "\naddPointFive on each element" << DEFAULT << std::endl;
	iter( doubleArray, 5, plusPointFive );
	iter( doubleArray, 5, printDouble );

	return 0;
}
