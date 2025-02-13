/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:21:15 by arissane          #+#    #+#             */
/*   Updated: 2025/02/10 14:30:01 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phnbk = PhoneBook();
	std::string	command;

	std::cout << "Please enter one of the following "
		"commands:\n\"ADD\", \"SEARCH\", or \"EXIT\"." << std::endl;
	while (std::cin.eof() == false)
	{
		command = get_input("Input:");
		if (command.compare("EXIT") == 0)
			break ;
		if (command.compare("ADD") == 0)
			phnbk.add();
		if (command.compare("SEARCH") == 0)
			phnbk.search();
	}
	return (0);
}
