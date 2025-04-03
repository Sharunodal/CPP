/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:10:44 by arissane          #+#    #+#             */
/*   Updated: 2025/03/18 13:38:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

# define CYAN "\033[1;36m"
# define DEFAULT "\033[0;0m"

class AForm;

class Bureaucrat {
	private:
		const			std::string _name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat(std::string customName, int customGrade);
		~Bureaucrat();

		Bureaucrat&	operator = (const Bureaucrat& source);

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form);

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator << (std::ostream &stream, const Bureaucrat &bureaucrat);

#endif
