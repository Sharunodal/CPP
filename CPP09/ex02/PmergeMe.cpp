/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:58:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/23 13:15:37 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>
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

std::vector<size_t>	PmergeMe::generateJacobsthalNumbers(size_t n)
{
	std::vector<size_t> jcbs = {0, 1};
	while (jcbs.back() < n)
	{
		jcbs.push_back(jcbs[jcbs.size() - 1] + 2 * jcbs[jcbs.size() - 2]);
	}
	return jcbs;
}

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
	//pairwise comparison and swap
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] < container[i + 1])
		{
			std::swap(container[i], container[i + 1]);
		}
	}
	//recursively sort larger elements
	Container	recursivelyLarger;
	for (size_t i = 0; i < container.size(); i += 2)
	{
		recursivelyLarger.push_back(container[i]);
	}
	fordJohnsonSort(recursivelyLarger);
	//rebuild with pend elements
	Container	sorted = recursivelyLarger;
	auto		jcbs = generateJacobsthalNumbers(container.size());
	//insert first element
	if (container.size() > 1)
	{
		size_t	position = binarySearchInsertPosition(sorted, container[1], sorted.size());
		sorted.insert(sorted.begin() + position, container[1]);
	}
	//insert remaining elements using the Jacobstahl sequence
	for (size_t i = 1; i < jcbs.size(); ++i)
	{
		for (size_t j = std::min(jcbs[i], container.size() - 1); j > jcbs[i - 1]; --j)
		{
			if (j % 2 == 0)
				continue;
			size_t	position = binarySearchInsertPosition(sorted, container[j], sorted.size());
			sorted.insert(sorted.begin() + position, container[j]);
		}
	}
}

void	PmergeMe::sort(int argc, char** argv)
{
	if (validateInput(argc, argv) == false)
	{
		throw std::runtime_error("Error: invalid input");
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
	for (size_t i = 0; i < _vectorArray.size(); ++i)
	{
		std::cout << _vectorArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vectorArray.size()
		<< " elements with std::vector: " << vectorTime.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeArray.size()
		<< " elements with std::deque: " << dequeTime.count() << " us" << std::endl;
}
