/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:09 by arissane          #+#    #+#             */
/*   Updated: 2025/03/10 10:50:20 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

void	testScavTrap()
{
	std::cout << RED << "\n\n[Commencing tests for ScavTrap]" << DEFAULT << std::endl;
	std::cout << "\nScavTrap def;" << std::endl;
	ScavTrap	def;
	def.printStats();
	def.attack("Dummy");
	def.guardGate();

	std::cout << "\nScavTrap test(\"Test\");" << std::endl;
	ScavTrap	test("Test");
	test.printStats();
	test.attack("Dummy");
	test.takeDamage(18);
	test.beRepaired(2);
	test.guardGate();
	test.printStats();

	std::cout << "\nScavTrap copy(test);" << std::endl;
	ScavTrap	copy(test);
	copy.setName("Copy");
	copy.printStats();
	copy.attack("Dummy");
	copy.guardGate();

	std::cout << "\nScavTrap custom(\"Custom\", 2, 2, 999);" << std::endl;
	ScavTrap	custom("Custom", 2, 2, 999);
	custom.printStats();
	custom.attack("Dummy");
	custom.guardGate();

	std::cout << "\ncopy = custom;" << std::endl;
	copy = custom;
	copy.setName("Copy");
	copy.attack("Dummy");
	custom.attack("Dummy");
	copy.guardGate();
}

void	testFragTrap()
{
	std::cout << RED << "\n\n[Commencing tests for FragTrap]" << DEFAULT << std::endl;
	std::cout << "\nFragTrap def;" << std::endl;
	FragTrap	def;
	def.printStats();
	def.highFivesGuys();

	std::cout << "\nFragTrap test(\"Test\");" << std::endl;
	FragTrap	test("Test");
	test.printStats();
	test.attack("Dummy");
	test.takeDamage(18);
	test.beRepaired(2);
	test.highFivesGuys();
	test.printStats();

	std::cout << "\nFragTrap copy(test);" << std::endl;
	FragTrap	copy(test);
	copy.setName("Copy");
	copy.printStats();
	copy.highFivesGuys();

	std::cout << "\nFragTrap custom(\"Custom\", 2, 2, 999);" << std::endl;
	FragTrap	custom("Custom", 2, 2, 999);
	custom.printStats();
	custom.highFivesGuys();

	std::cout << "\ncopy = custom;" << std::endl;
	copy = custom;
	copy.setName("Copy");
	copy.attack("Dummy");
	custom.attack("Dummy");
	copy.highFivesGuys();
}

int	main(void)
{
	testClapTrap();
	testScavTrap();
	testFragTrap();

	return 0;
}
