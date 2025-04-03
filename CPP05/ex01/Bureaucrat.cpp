/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:10:19 by arissane          #+#    #+#             */
/*   Updated: 2025/03/18 13:38:20 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name(source._name), _grade(source._grade)
{
}

Bureaucrat::Bureaucrat(std::string customName, int customGrade) : _name(customName)
{
	if (customGrade > 150)
	{
		throw GradeTooLowException();
	}
	else if (customGrade < 1)
	{
		throw GradeTooHighException();
	}
	else
	{
		_grade = customGrade;
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& source)
{
	if (this != &source)
	{
		_grade = source._grade;
	}
	return *this;
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade > 1)
	{
		_grade -= 1;
	}
	else
	{
		throw GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade()
{
	if (_grade < 150)
	{
		_grade += 1;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		if (form.getSignedStatus() == false)
		{
			form.beSigned(*this);
			std::cout << _name << " signed " <<form.getName() << std::endl;
		}
		else
		{
			std::cout << _name << " couldn't sign " << form.getName() << ", because the form was already signed." << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << ", because " << e.what() << std::endl;
	}
	
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

std::ostream& operator << (std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade = " << bureaucrat.getGrade() << ".";
	return stream;
}
