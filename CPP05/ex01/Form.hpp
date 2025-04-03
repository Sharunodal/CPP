/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:13:10 by arissane          #+#    #+#             */
/*   Updated: 2025/03/31 11:19:41 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form();
		Form(const Form& source);
		Form(std::string customName, bool signedStatus, int customGradeToSign, int customGradeToExecute);
		~Form();

		Form&	operator = (const Form& source);

		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator << (std::ostream &stream, const Form &bureaucrat);

#endif
