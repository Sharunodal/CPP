/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:36:54 by arissane          #+#    #+#             */
/*   Updated: 2025/04/16 12:03:12 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_vector;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& source);
		~Span();
		Span& operator=(const Span& source);
		void	addNumber(int number);
		int	shortestSpan();
		int	longestSpan();
		void	addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
};

#endif
