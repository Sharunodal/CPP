/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:49:48 by arissane          #+#    #+#             */
/*   Updated: 2025/02/13 11:01:26 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int	main( void )
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	// Address
	std::cout << "Memory address of the string:\n" << &brain << std::endl;
	std::cout << "Memory address held by stringPTR:\n" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\n" << &stringREF << std::endl;

	// Value
	std::cout << "Value of the string variable:\n" << brain << std::endl;
	std::cout << "Value pointed to by stringPTR:\n" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\n" << stringREF << std::endl;
	return ( 0 );
}
