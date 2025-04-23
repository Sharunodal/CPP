/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:58:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/23 13:44:53 by arissane         ###   ########.fr       */
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
	Container	main_chain;
	Container	pend;
	//pair creation and separation
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] < container[i + 1])
		{
			std::swap(container[i], container[i + 1]);
			main_chain.push_back(container[i]);
			pend.push_back(container[i + 1]);
		}
	}
	//handle odd element
	if (container.size() % 2)
	{
		pend.push_back(container.back());
	}
	//Recursively sort the main chain
	fordJohnsonSort(main_chain);
	//insert pend elements following the Jacobstahl sequence
	auto	jcbs_sequence = generateJacobsthalNumbers(pend.size());
	size_t	last_inserted = 0;
	for (size_t jcbs_index = 0; jcbs_index < jcbs_sequence.size(); ++jcbs_index)
	{
		size_t	current = jcbs_sequence[jcbs_index];
		for (size_t i = std::min(current, pend.size() - 1); i > last_inserted; --i)
		{
			size_t	insert_position = binarySearchInsertPosition(main_chain, pend[i], main_chain.size());
			main_chain.insert(main_chain.begin() + insert_position, pend[i]);
		}
		last_inserted = current;
	}
	container = main_chain;
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
