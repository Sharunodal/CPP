/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:09:22 by arissane          #+#    #+#             */
/*   Updated: 2025/04/11 10:35:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

Base*	generate(void)
{
	int	random;
	std::srand(time(NULL));
	random = rand() % 3;

	if (random == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return new C();
	}
}

void	identify(Base* p)
{
	std::cout << "Identified object type ";
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A";
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B";
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C";
	}
	else
	{
		std::cout << "unknown";
	}
	std::cout << " from the pointer" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified object type A from the reference" << std::endl;
	}
	catch (std::bad_cast& error)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Identified object type B from the reference" << std::endl;
		}
		catch (std::bad_cast& error)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Identified object type C from the reference" << std::endl;
			}
			catch (std::bad_cast& error)
			{
				std::cout << "Identified object type unknown from the reference" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;

	return 0;
}
