/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:39:54 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:34:50 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", false, 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string targetOfExecute) :
	AForm("RobotomyRequestForm", false, 72, 45), _target(targetOfExecute)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& source) :
	AForm(source), _target(source._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&  RobotomyRequestForm::operator = (const RobotomyRequestForm& source)
{
    if (this != &source)
    {
        _target = source._target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getGradeToExecute() < executor.getGrade())
    {
        throw GradeTooLowException();
    }
    else if (getSignedStatus() == false)
    {
        throw FormNotSignedException();
    }
    else
    {
        std::cout << "*ZzzZZzz ZZzzzzZZzz ZZZzzZZZzzz*" << std::endl;
        std::srand(std::time(0));
        int success = std::rand() % 2;
        if (success == 1)
        {
            std::cout << this->getTarget() << " has been robotomised" << std::endl;
        }
        else
        {
            std::cerr << this->getTarget() << " robotomisation has failed" << std::endl;
        }
    }
}
