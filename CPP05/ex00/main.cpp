/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:41 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 11:00:05 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void    basicTests()
{
	std::cout << CYAN << "Bureaucrat def;" << DEFAULT << std::endl;
	Bureaucrat  def;
	std::cout << def << std::endl;
	try
	{
		std::cout << CYAN << "def.decrementGrade();" << DEFAULT << std::endl;
		def.decrementGrade();
		std::cout << def << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\nBureaucrat custom(Jason, 20);" << DEFAULT << std::endl;
	Bureaucrat custom("Jason", 2);
	std::cout << custom << std::endl;
	try
	{
		std::cout << CYAN << "custom.incrementGrade();" << DEFAULT << std::endl;
		custom.incrementGrade();
		std::cout << custom << std::endl;
		std::cout << CYAN << "custom.decrementGrade();" << DEFAULT << std::endl;
		custom.decrementGrade();
		std::cout << custom << std::endl;
		std::cout << CYAN << "2x custom.incrementGrade();" << DEFAULT << std::endl;
		custom.incrementGrade();
		custom.incrementGrade();
		std::cout << custom << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\nBureaucrat copy(custom);" << DEFAULT << std::endl;
	Bureaucrat copy(custom);
	std::cout << copy << std::endl;
	
	std::cout << CYAN << "\ndef = copy;" << DEFAULT << std::endl;
	def = copy;
	std::cout << def << std::endl;
	std::cout << CYAN << "The _name is a constant, so it cannot be copied without creating a new Bureaucrat" << DEFAULT << std::endl;
	
	try
	{
		std::cout << CYAN << "\nBureaucrat wrong_custom(\"Wrong\", 160);" << DEFAULT << std::endl;
		Bureaucrat wrong_custom("Wrong", 160);
		std::cout << wrong_custom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << CYAN << "\nBureaucrat wrong_custom(\"Wrong\", 0);" << DEFAULT << std::endl;
		Bureaucrat wrong_custom("Wrong", 0);
		std::cout << wrong_custom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
    basicTests();

    return 0;
}
