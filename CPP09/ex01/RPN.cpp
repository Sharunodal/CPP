/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:37 by arissane          #+#    #+#             */
/*   Updated: 2025/04/22 13:52:51 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <stdexcept>
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN& source)
{
	_stack = source._stack;
}

RPN&	RPN::operator=(const RPN& source)
{
	if (this != &source)
		_stack = source._stack;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::calculate(std::string str)
{
	std::istringstream	inputstream(str);
	std::string		token;
	while (inputstream >> token)
	{
		if (token.length() == 1)
		{
			char	c = token[0];
			if (isdigit(c))
			{
				_stack.push(c - '0');
				continue;
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				if (_stack.size() < 2)
				{
					std::cerr << "Error: not enough operands for operator " << c << std::endl;
					return;
				}
				int	b = _stack.top();
				_stack.pop();
				int	a = _stack.top();
				_stack.pop();
				switch (c)
				{
					case '+':
						_stack.push(a + b);
						break;
					case '-':
						_stack.push(a - b);
						break;
					case '*':
						_stack.push(a * b);
						break;
					case '/':
						if (b == 0)
						{
							std::cerr << "Error: division by zero" << std::endl;
						}
						_stack.push(a / b);
						break;
				}
				continue;
			}
		}
		std::cerr << "Error: invalid token '" << token << "'" << std::endl;
		return;
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}
