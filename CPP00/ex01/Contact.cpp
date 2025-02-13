/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:13:35 by arissane          #+#    #+#             */
/*   Updated: 2025/02/10 13:15:21 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	index = 0;
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(int id, std::string fname, std::string lname, std::string nname,
		std::string phn, std::string darksec)
{
	index = id;
	first_name = fname;
	last_name = lname;
	nickname = nname;
	phone_number = phn;
	darkest_secret = darksec;
}

std::string	trim_string(std::string str)
{
	size_t	len;

	len = str.length();
	if (len > 10)
		return (str.replace(9, len, "."));
	return (str);
}

void	Contact::display_info()
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << trim_string(first_name) << "|";
	std::cout << std::setw(10) << trim_string(last_name) << "|";
	std::cout << std::setw(10) << trim_string(nickname) << std::endl;
}

void	Contact::display_full_info()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}
