/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:58:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/24 11:24:43 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <chrono>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& source) :
	_vectorArray(source._vectorArray), _dequeArray(source._dequeArray)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& source)
{
	if (this != &source)
	{
		_vectorArray = source._vectorArray;
		_dequeArray = source._dequeArray;
	}
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
void	PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream	inputStream(argv[i]);
		int			number;
		inputStream >> number;
		_vectorArray.push_back(number);
		_dequeArray.push_back(number);
	}
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

/**
 * *Knuth's version has variable k that tracks the pass number through all pile
 * operations and insertions. This version simulates it by using recursion and
 * doing controlled insertions into the main chain using the Jacobsthal sequence.
 */
template <typename Container>
void	PmergeMe::fordJohnsonSort(Container& container)
{
	if (container.size() <= 1)
	{
		return;
	}
	std::vector<std::pair<int, int>>	pairs;
	Container				main_chain;
	std::vector<int>			pend;
	// Step R1: Pair elements
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];
		if (a > b)
		{
			std::swap(a, b);
		}
		pairs.emplace_back(a, b);//store pairs as (smaller, larger)
		main_chain.push_back(b);//larger number to the main chain
		pend.push_back(a);//smaller number to pend
	}
	bool size_is_odd = (container.size() % 2 != 0);
	if (size_is_odd == true)
	{
		pend.push_back(container.back());
	}
	// Step R2 - R5: Sort main_chain recursively
	fordJohnsonSort(main_chain);
	// Step R6: Insert pend elements using Jacobsthal ordering
	std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pend.size());//R3 Extract kth digit of key => Adapted comparison-based algorithm to a container-based implementation
	std::vector<bool> inserted(pend.size(), false);//Represents empty piles R2(original clears TOP[i] and BOTM[i])
	for (size_t j = 1; j < jacobsthal.size(); ++j)//R5 stepping through records of pend in Jacobsthal order
	{
		size_t start = jacobsthal[j];
		size_t end = jacobsthal[j - 1];
		for (size_t k = start; k > end; --k)
		{
			size_t index = k - 1;
			if (index < pend.size() && inserted[index] == false)
			{
				size_t pos = binarySearchInsertPosition(main_chain, pend[index], main_chain.size());
				//R4 records are linked to piles. Instead of linking records, inserting into the main chain in a positionally correct
				//manner while preserving the sort order is a modern c++ equivalent of adjusting links between nodes
				main_chain.insert(main_chain.begin() + pos, pend[index]);
				inserted[index] = true;
			}
		}
	}
	// Insert final element if skipped
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

void	PmergeMe::sort(int argc, char** argv)
{
	if (validateInput(argc, argv) == false)
	{
		throw std::runtime_error("Error");
	}
	parseInput(argc, argv);

	if (_vectorArray.empty() == true)
	{
		return;
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorArray.size(); ++i)
	{
		std::cout << _vectorArray[i] << " ";
	}
	std::cout << std::endl;

	//Since we are using containers, there are no explicit link structures or record objects
	std::vector<int>	vectorCopy = _vectorArray;
	std::deque<int>		dequeCopy = _dequeArray;

	auto	start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(vectorCopy);
	auto	end = std::chrono::high_resolution_clock::now();
	auto	vectorTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	start = std::chrono::high_resolution_clock::now();
	fordJohnsonSort(dequeCopy);
	end = std::chrono::high_resolution_clock::now();
	auto	dequeTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "After: ";
	for (size_t i = 0; i < vectorCopy.size(); ++i)
	{
		std::cout << vectorCopy[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vectorArray.size()
		<< " elements with std::vector: " << vectorTime.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeArray.size()
		<< " elements with std::deque: " << dequeTime.count() << " us" << std::endl;
}
