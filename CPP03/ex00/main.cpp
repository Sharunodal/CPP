/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:09 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 10:49:14 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	testClapTrap()
{
	std::cout << RED << "[Commencing tests for ClapTrap]" << DEFAULT << std::endl;
	std::cout << "\nClapTrap def;" << std::endl;
	ClapTrap	def;
	def.printStats();
	def.attack("Dummy");
	def.takeDamage(9);
	def.printStats();

	std::cout << "\nClapTrap a(\"Test\");" << std::endl;
	ClapTrap	a("Test");
	a.printStats();
	a.attack("Dummy");
	a.printStats();
	a.takeDamage(2);
	a.printStats();
	a.beRepaired(1);
	a.printStats();
	a.attack("Dummy");
	a.takeDamage(2);
	a.beRepaired(1);
	a.attack("Dummy");
	a.takeDamage(2);
	a.beRepaired(1);
	a.attack("Dummy");
	a.takeDamage(2);
	a.beRepaired(1);
	a.attack("Dummy");
	a.takeDamage(2);
	a.beRepaired(5);
	a.printStats();
	a.attack("Dummy");
	a.beRepaired(1);
	a.takeDamage(1000);
	a.printStats();
	a.attack("Dummy");
	a.beRepaired(1);
	a.printStats();

	std::cout << "\nClapTrap copy(a);" << std::endl;
	ClapTrap	copy(a);
	copy.setName("Copy");
	copy.printStats();
	copy.attack("Dummy");
	copy.beRepaired(1);

	std::cout << "\nClapTrap custom(\"Custom\", 2, 2, 9999);" << std::endl;
	ClapTrap	custom("Custom", 2, 3, 9999);
	custom.printStats();
	custom.attack("Dummy");
	custom.takeDamage(1);
	custom.beRepaired(9999);

	std::cout << "\ncopy = custom;" << std::endl;
	copy = custom;
	copy.setName("Copy");
	copy.printStats();
	copy.attack("Dummy");
	custom.attack("Dummy");
}

int	main(void)
{
	testClapTrap();

	return 0;
}
