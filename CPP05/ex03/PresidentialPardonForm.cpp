/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:22 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:32:08 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string targetOfExecute) :
	AForm("PresidentialPardonForm", false, 25, 5), _target(targetOfExecute)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& source) :
	AForm(source), _target(source._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&  PresidentialPardonForm::operator = (const PresidentialPardonForm& source)
{
    if (this != &source)
    {
        _target = source._target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}
