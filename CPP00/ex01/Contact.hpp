/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:15:34 by arissane          #+#    #+#             */
/*   Updated: 2025/02/10 11:41:42 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		int		index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		Contact(int id,
			std::string fname,
			std::string lname,
			std::string nname,
			std::string phn,
			std::string darksec);
		void	display_info();
		void	display_full_info();
};
#endif
