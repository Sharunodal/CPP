/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:02 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 09:35:35 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string     _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string targetOfExecute);
		RobotomyRequestForm(RobotomyRequestForm& source);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator = (const RobotomyRequestForm& source);

		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
