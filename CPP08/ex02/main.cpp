/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:45:14 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 12:08:03 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int subjectTests()
{
	std::cout << "Main from the subject:" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}

int	listTests()
{
	std::cout << "\nThe same tests using list:" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;
	
	lst.pop_back();
	
	std::cout << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}

int extraTests()
{
	std::cout << "\nExtra tests:" << std::endl;
	MutantStack<int> mstack;
	const MutantStack<int>& constMstack = mstack;
	
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	std::cout << "const iterator:" << std::endl;
	MutantStack<int>::const_iterator c_it = constMstack.begin();
	MutantStack<int>::const_iterator c_ite = constMstack.end();
	while (c_it != c_ite)
	{
		std::cout << *c_it << std::endl;
		++c_it;
	}

	std::cout << "\nreverse iterator:" << std::endl;
	MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack.rend();
	while (r_it != r_ite)
	{
		std::cout << *r_it << std::endl;
		++r_it;
	}

	std::cout << "\nconst reverse iterator:" << std::endl;
	MutantStack<int>::const_reverse_iterator cr_it = constMstack.rbegin();
	MutantStack<int>::const_reverse_iterator cr_ite = constMstack.rend();
	while (cr_it != cr_ite)
	{
		std::cout << *cr_it << std::endl;
		++cr_it;
        }

	return 0;
}

int	main()
{
	subjectTests();
	listTests();
	extraTests();

	return 0;
}
