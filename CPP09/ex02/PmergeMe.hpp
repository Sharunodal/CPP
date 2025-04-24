/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:08 by arissane          #+#    #+#             */
/*   Updated: 2025/04/23 11:45:43 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm>
# include <stdexcept>
# include <climits>

class PmergeMe
{
	private:
		std::vector<int>	_vectorArray;
		std::deque<int>		_dequeArray;

		bool	validateInput(int argc, char** argv);
		void	parseInput(int argc, char** argv);
		std::vector<size_t>	generateJacobsthalNumbers(size_t n);

		template <typename Container>
		size_t	binarySearchInsertPosition(Container& container, int value, size_t right);

		template <typename Container>
		void	fordJohnsonSort(Container& container);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		void	sort(int argc, char** argv);
};

#endif
