/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:45:41 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 10:33:35 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& source);
		MutantStack&	operator=(const MutantStack& source);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator	begin();
		iterator	end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "MutantStack.tpp"

#endif
