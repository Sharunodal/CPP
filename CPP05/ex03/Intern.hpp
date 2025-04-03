/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:55:50 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 10:00:39 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
	public:
		Intern();
		Intern(const Intern& source);
		~Intern();

		Intern&	operator = (const Intern& source);

		AForm	*makeForm(std::string form, std::string target);
		static AForm*  makeShrubbery(const std::string& target);
		static AForm*  makeRobotomy(const std::string& target);
		static AForm*  makePresidential(const std::string& target);
};

#endif
