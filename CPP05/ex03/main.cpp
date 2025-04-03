/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:41 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 10:33:27 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	std::cout << CYAN << "Bureaucrat slartibartfast(\"Slartibartfast\", 5);" << DEFAULT << std::endl;
	Bureaucrat  slartibartfast("Slartibartfast", 5);
	std::cout << slartibartfast << std::endl;

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
	tryExecuteForm(slartibartfast, shrubbery);
	tryExecuteForm(slartibartfast, robotomy);
	tryExecuteForm(slartibartfast, presidential);
}

void	internTests()
{
	Bureaucrat  zaphod("Zaphod", 5);
	std::cout << CYAN << "\nIntern intern;" << DEFAULT << std::endl;
	Intern	intern;
	std::cout << CYAN << "AForm* shrubbery = intern.makeForm(\"ShrubberyCreationForm\", \"Home\");" << DEFAULT << std::endl;
	AForm* shrubbery = intern.makeForm("ShrubberyCreationForm", "Home");
	std::cout << CYAN << "AForm* robotomy = intern.makeForm(\"RobotomyRequestForm\", \"Arthur\");" << DEFAULT << std::endl;
	AForm* robotomy = intern.makeForm("RobotomyRequestForm", "Arthur");
	std::cout << CYAN << "AForm* presidential = intern.makeForm(\"PresidentialPardonForm\", \"Ford\");" << DEFAULT << std::endl;
	AForm* presidential = intern.makeForm("PresidentialPardonForm", "Ford");
	std::cout << CYAN << "AForm* towel = intern.makeForm(\"TowelOrderForm\", \"Zaphod\");" << DEFAULT << std::endl;
	AForm* towel = intern.makeForm("TowelOrderForm", "Zaphod");

	std::cout << CYAN << "\nZaphod attempts to execute all forms" << DEFAULT << std::endl;
	tryExecuteForm(zaphod, *shrubbery);
	delete shrubbery;
	tryExecuteForm(zaphod, *robotomy);
	delete robotomy;
	tryExecuteForm(zaphod, *presidential);
	delete presidential;
	if (towel != nullptr)
	{
		tryExecuteForm(zaphod, *towel);
		delete towel;
	}
}

int	main()
{
	basicTests();
	formTests();
	internTests();

	return 0;
}
