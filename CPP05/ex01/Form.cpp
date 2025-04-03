/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:12:53 by arissane          #+#    #+#             */
/*   Updated: 2025/03/31 11:13:04 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
        _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(const Form& source) :
        _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{
}

Form::Form(std::string customName, bool signedStatus, int customGradeToSign, int customGradeToExecute) :
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

Form::~Form()
{
}

Form&   Form::operator = (const Form& source)
{
    if (this != &source)
    {
        _signed = source._signed;
    }
    return *this;
}

const std::string&  Form::getName() const
{
    return _name;
}

bool    Form::getSignedStatus() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
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

const char	*Form::GradeTooLowException::what() const throw()
{
	return "their grade is too low!";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "their grade is too high!";
}

std::ostream& operator << (std::ostream &stream, const Form &form)
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