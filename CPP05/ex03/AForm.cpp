/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:55 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:30:31 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
}

AForm::AForm(const AForm& source) :
	_name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{
}

AForm::AForm(std::string customName, bool signedStatus, int customGradeToSign, int customGradeToExecute) :
	_name(customName), _signed(signedStatus), _gradeToSign(customGradeToSign), _gradeToExecute(customGradeToExecute)
{
    if (customGradeToSign > 150 || customGradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
    if (customGradeToSign < 1 || customGradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
}

AForm::~AForm()
{
}

AForm&   AForm::operator = (const AForm& source)
{
    if (this != &source)
    {
        _signed = source._signed;
    }
    return *this;
}

const std::string&  AForm::getName() const
{
    return _name;
}

bool    AForm::getSignedStatus() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (_signed == true)
    {
        std::cout << "The form is already signed" << std::endl;
        return ;
    }
    else if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw GradeTooLowException();
    }
    else
    {
        _signed = true;
    }
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "their grade is too low!";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "their grade is too high!";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "The form has not been signed!";
}

std::ostream& operator << (std::ostream &stream, const AForm &form)
{
    std::string signedStatus;
    if (form.getSignedStatus() == true)
    {
        signedStatus = "yes";
    }
    else
    {
        signedStatus = "no";
    }
	stream << "***************************************\n"
        << "Form name: " << form.getName() << "\n"
        << "Signed: " << signedStatus << "\n"
        << "Grade required in order to sign: " << form.getGradeToSign() << "\n"
        << "Grade required in order to execute: " << form.getGradeToExecute() << "\n"
        << "***************************************\n";
	return stream;
}
