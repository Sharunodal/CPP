/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:41 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:46:55 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void    tryExecuteForm(Bureaucrat& person, AForm& form)
{
	try
	{
		person.signForm(form);
		person.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form << std::endl;
}

void    formTests()
{
	std::cout << CYAN << "\nBureaucrat arthur(\"Arthur\", 150);" << DEFAULT << std::endl;
	Bureaucrat  arthur("Arthur", 150);
	std::cout << arthur << std::endl;
	std::cout << CYAN << "Bureaucrat jeff(\"Jeff\", 46);" << DEFAULT << std::endl;
	Bureaucrat  jeff("Jeff", 46);
	std::cout << jeff << std::endl;
	std::cout << CYAN << "Bureaucrat Slartibartfast(\"Slartibartfast\", 5);" << DEFAULT << std::endl;
	Bureaucrat  Slartibartfast("Slartibartfast", 5);
	std::cout << Slartibartfast << std::endl;

	std::cout << CYAN << "\nShrubberyCreationForm shrubbery\"Home\");" << DEFAULT << std::endl;
	ShrubberyCreationForm    shrubbery("Home");
	std::cout << shrubbery << std::endl;
	std::cout << CYAN << "RobotomyRequestForm robotomy\"Arthur\");" << DEFAULT << std::endl;
	RobotomyRequestForm    robotomy("Arthur");
	std::cout << robotomy << std::endl;
	std::cout << CYAN << "PresidentialPardonForm presidential\"Arthur\");" << DEFAULT << std::endl;
	PresidentialPardonForm    presidential("Arthur");
	std::cout << presidential << std::endl;

	std::cout << CYAN << "Arthur attempts to execute all forms" << DEFAULT << std::endl;
	tryExecuteForm(arthur, shrubbery);
	tryExecuteForm(arthur, robotomy);
	tryExecuteForm(arthur, presidential);
	
	std::cout << CYAN << "Jeff attempts to execute all forms" << DEFAULT << std::endl;
	tryExecuteForm(jeff, shrubbery);
	tryExecuteForm(jeff, robotomy);
	tryExecuteForm(jeff, presidential);
	std::cout << CYAN << "jeff.incrementGrade();" << DEFAULT << std::endl;
	jeff.incrementGrade();
	std::cout << CYAN << "Jeff retries executing RobotomyRequestForm" << DEFAULT << std::endl;
	tryExecuteForm(jeff, robotomy);
	
	std::cout << CYAN << "Slartibartfast attempts to execute all forms" << DEFAULT << std::endl;
	tryExecuteForm(Slartibartfast, shrubbery);
	tryExecuteForm(Slartibartfast, robotomy);
	tryExecuteForm(Slartibartfast, presidential);
}

int	main()
{
	basicTests();
	formTests();

	return 0;
}
