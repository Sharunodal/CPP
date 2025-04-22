/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:06 by arissane          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:48 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;
	public:
		RPN();
		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);
		~RPN();

		void	calculate(std::string str);
};

#endif
