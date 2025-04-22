/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:08 by arissane          #+#    #+#             */
/*   Updated: 2025/04/22 14:08:02 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class Pmerge
{
	private:
		std::vector<int>	_vectorArray;
		std::deque<int>		_dequeArray;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& source);
		Pmerge& operator=(const PmergeMe& source);
		~PmergeMe();
}

#endif
