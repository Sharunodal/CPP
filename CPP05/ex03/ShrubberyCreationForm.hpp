/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:39:36 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:34:20 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string     _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string targetOfExecute);
		ShrubberyCreationForm(ShrubberyCreationForm& source);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator = (const ShrubberyCreationForm& source);

		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
