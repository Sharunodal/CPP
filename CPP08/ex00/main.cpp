/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:56:28 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 13:15:14 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <iostream>

void	vectorTests()
{
	std::cout << "Vector tests:" << std::endl;
	std::vector<int> vec = {1, 2, 3, 4, 5};
	try
	{
		easyfind(vec, 3);
		easyfind(vec, 5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	notFoundTest()
{
	std::cout << "\nNot found test:" << std::endl;
	std::vector<int> vec = {10, 20, 30};
	try
	{
		easyfind(vec, 42);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	emptyContainerTest()
{
	std::cout << "\nEmpty container test:" << std::endl;
	std::vector<int> empty;
	try
	{
		easyfind(empty, 1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	differentContainerTests()
{
	std::cout << "\nDifferent container tests:" << std::endl;

	std::list<int> lst = {5, 10, 15};
	try
	{
		easyfind(lst, 10);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::deque<int> deq = {100, 200, 300};
	try
	{
		easyfind(deq, 200);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	constContainerTest()
{
	std::cout << "\nConst container test:" << std::endl;
	const std::vector<int> vec = {1, 2, 3};
	try
	{
		easyfind(vec, 2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	vectorTests();
	notFoundTest();
	emptyContainerTest();
	differentContainerTests();
	constContainerTest();

	return 0;
}
