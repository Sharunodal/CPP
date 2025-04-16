/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:37:25 by arissane          #+#    #+#             */
/*   Updated: 2025/04/16 12:02:54 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span& source)
{
	if (this != &source)
	{
		_N = source._N;
		_vector = source._vector;
	}
}

Span&	Span::operator=(const Span& source)
{
	if (this != &source)
	{
		_N = source._N;
		_vector = source._vector;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_vector.size() < _N)
	{
		_vector.push_back(number);
	}
	else
	{
		throw std::runtime_error("Span is full, cannot add numbers");
	}
}

int	Span::shortestSpan()
{
	if (_vector.size() < 2)
	{
		throw std::runtime_error("Size is too small for a span to be found");
	}
	std::vector<int> sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	int	shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		shortest = std::min(shortest, (sorted[i + 1] - sorted[i]));
	}
	return shortest;
}

int	Span::longestSpan()
{
	if (_vector.size() < 2)
	{
		throw std::runtime_error("Size is too small for a span to be found");
	}
	int	maximum = *std::max_element(_vector.begin(), _vector.end());
	int	minimum = *std::min_element(_vector.begin(), _vector.end());
	int	result = maximum - minimum;
	return (result);
}

void	Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (std::distance(first, last) > static_cast<int>(_N - _vector.size()))
	{
		throw std::runtime_error("Span does not have enough space to add the range of numbers");
	}
	_vector.insert(_vector.end(), first, last);
}
