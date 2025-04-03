/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:41:01 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:31:00 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm();
		AForm(const AForm& source);
		AForm(std::string customName, bool signedStatus, int customGradeToSign, int customGradeToExecute);
		virtual ~AForm();

		AForm&	operator = (const AForm& source);

		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void        execute(const Bureaucrat& bureaucrat) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator << (std::ostream &stream, const AForm &bureaucrat);

#endif
