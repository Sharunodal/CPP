/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:45:41 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 11:53:47 by arissane         ###   ########.fr       */
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
		iterator	begin();
		iterator	end();
		
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const;
		const_iterator	end() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif
