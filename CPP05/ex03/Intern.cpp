/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:55:18 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 10:03:59 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& source)
{
    (void)source;
}

Intern::~Intern()
{
}

Intern&	Intern::operator = (const Intern& source)
{
    (void)source;
    return *this;
}

AForm*  Intern::makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makePresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
    std::string formTypes[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm*  (*functions[3])(const std::string& target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

    for (int i = 0; i < 3; i++)
    {
        if (form == formTypes[i])
        {
            std::cout << "Intern creates " << formTypes[i] << std::endl;
            return functions[i](target);
        }
    }
    std::cout << "Intern failed to create the form. The form type \"" << form << "\" doesn't exist" << std::endl;
    return 0;
}
