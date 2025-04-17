/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:37:47 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 12:50:07 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void	basicTests()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	exceptionTests()
{
	std::cout << "\nException Tests:" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(42);
		sp.addNumber(43);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void largeSpanTests()
{
	std::cout << "\nLarge Span Tests:" << std::endl;
	Span sp(10000);
	std::srand(std::time(NULL));

	for (int i = 0; i < 10000; ++i)
	{
		sp.addNumber(std::rand());
	}
	
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	rangeInsertTests()
{
	std::cout << "\nRange Insert Tests:" << std::endl;
	Span sp(10);
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	sp.addRange(numbers.begin(), numbers.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try
	{
		std::vector<int> tooMany(20, 42);
		sp.addRange(tooMany.begin(), tooMany.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int	main()
{
	basicTests();
	exceptionTests();
	largeSpanTests();
	rangeInsertTests();

	return 0;
}
