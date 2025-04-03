/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:31 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:33:03 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string     _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string targetOfExecute);
		PresidentialPardonForm(PresidentialPardonForm& source);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator = (const PresidentialPardonForm& source);

		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
