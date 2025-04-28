/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:58:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/28 10:04:58 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <chrono>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& source)
{
	(void)source;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& source)
{
	(void)source;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

/**
 * There must be at least one number
 * Only positive integers
 */
bool	PmergeMe::validateInput(int argc, char** argv)
{
	if (argc < 2)
	{
		return false;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string	arg = argv[i];
		if (arg.empty())
		{
			return false;
		}
		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (isdigit(arg[j] == false) && !(j == 0 && arg[j] == '+'))
			{
				return false;
			}
		}
		std::istringstream inputStream(arg);
		long	number;
		inputStream >> number;
		if (number <= 0 || number > INT_MAX)
		{
			return false;
		}
	}
	return true;
}

/**
 * Convert valid arguments into integers and store to arrays
 */
template <typename Container>
Container	PmergeMe::parseInput(int argc, char** argv)
{
	Container	container;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream	inputStream(argv[i]);
		int			number;
		inputStream >> number;
		container.push_back(number);
	}
	return container;
}

/**
 * Create a vector of Jacobsthal numbers, used to guide how
 * elements are inserted from pend into the sorted list.
 * Each number is the previous number + 2x the one before the previous
 * example: 0 1 1 3 5 11 21 43 85 171
 */
std::vector<size_t>	PmergeMe::generateJacobsthalNumbers(size_t n)
{
	std::vector<size_t> jcbs = {0, 1};
	while (jcbs.back() < n)
	{
		jcbs.push_back(jcbs[jcbs.size() - 1] + 2 * jcbs[jcbs.size() - 2]);
	}
	return jcbs;
}

/**
 * Find where to insert the 'value' in a sorted container up to index 'right'
 */
template <typename Container>
size_t	PmergeMe::binarySearchInsertPosition(Container& container, int value, size_t right)
{
	size_t	left = 0;
	while (left < right)
	{
		size_t	middle = left + (right - left) / 2;
		if (value < container[middle])
		{
			right = middle;
		}
		else
		{
			left = middle + 1;
		}
	}
	return left;
}

template <typename Container>
void	PmergeMe::fordJohnsonSort(Container& container)
{
	if (container.size() <= 1)
	{
		return;
	}
	Container	main_chain;
	Container	pend;
	//Pair elements
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];
		if (a > b)
		{
			std::swap(a, b);
		}
		main_chain.push_back(b);//larger number to the main chain
		pend.push_back(a);//smaller number to pend
	}
	bool size_is_odd = (container.size() % 2 != 0);
	if (size_is_odd == true)
	{
		pend.push_back(container.back());
	}
	//Sort main_chain recursively
	fordJohnsonSort(main_chain);
	//Insert pend elements using Jacobsthal ordering
	std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	for (size_t j = 1; j < jacobsthal.size(); ++j)
	{
		size_t start = jacobsthal[j];
		size_t end = jacobsthal[j - 1];
		for (size_t k = start; k > end; --k)
		{
			size_t index = k - 1;
			if (index < pend.size() && inserted[index] == false)
			{
				size_t pos = binarySearchInsertPosition(main_chain, pend[index], main_chain.size());
				main_chain.insert(main_chain.begin() + pos, pend[index]);
				inserted[index] = true;
			}
		}
	}
	//Make sure all elements are inserted
	for (size_t i = 0; i < pend.size(); ++i)
	{
		if (inserted[i] == false)
		{
			size_t pos = binarySearchInsertPosition(main_chain, pend[i], main_chain.size());
			main_chain.insert(main_chain.begin() + pos, pend[i]);
		}
	}

	container = main_chain;
}

void	PmergeMe::sort(int argc, char** argv, int type)
{
	auto	start = std::chrono::high_resolution_clock::now();
	if (validateInput(argc, argv) == false)
	{
		throw std::runtime_error("Error");
	}
	if (type == 1)
	{
		std::vector<int>	vectorArray = parseInput<std::vector<int>>(argc, argv);
		if (vectorArray.empty() == true)
		{
			return;
		}
		std::vector<int>	vectorCopy = vectorArray;
		fordJohnsonSort(vectorArray);
		auto	end = std::chrono::high_resolution_clock::now();
		auto	vectorTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout << "Before: ";
		for (size_t i = 0; i < vectorCopy.size(); ++i)
		{
			std::cout << vectorCopy[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "After: ";
		for (size_t i = 0; i < vectorArray.size(); ++i)
		{
			std::cout << vectorArray[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << vectorArray.size()
			<< " elements with std::vector: " << vectorTime.count() << " us" << std::endl;
	}
	else if (type == 2)
	{
		std::deque<int>	dequeArray = parseInput<std::deque<int>>(argc, argv);
		if (dequeArray.empty() == true)
		{
			return;
		}
		std::deque<int>	dequeCopy = dequeArray;
		fordJohnsonSort(dequeArray);
		auto	end = std::chrono::high_resolution_clock::now();
		auto	dequeTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout << "Time to process a range of " << dequeArray.size()
			<< " elements with std::deque: " << dequeTime.count() << " us" << std::endl;
	}
	else
	{
		throw std::runtime_error("Error");
	}
}
