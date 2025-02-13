/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:20:51 by arissane          #+#    #+#             */
/*   Updated: 2025/02/10 14:10:11 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	get_input(std::string prompt)
{
	std::string	input = "";

	if (std::cin.eof())
		return (input);
	std::cout << prompt << std::endl;
	std::getline(std::cin, input);
	return (input);
}

bool	is_valid_index(std::string input, int count)
{
	int	number;

	if (input.empty() == true || input.length() > 1)
		return (false);
	number = input.at(0) - '0';
	if (number > 0 && number <= count)
		return (true);
	return (false);
}

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

void	PhoneBook::add()
{
	std::string	first_name = get_input("First name: ");
	std::string	last_name = get_input("Last name: ");
	std::string	nickname = get_input("Nickname: ");
	std::string	phone_number = get_input("Phone number: ");
	std::string	darkest_secret = get_input("Darkest secret: ");
	if (std::cin.eof() == true)
		return ;
	if (first_name.empty() || last_name.empty() || nickname.empty()
			|| phone_number.empty() || darkest_secret.empty())
	{
		std::cout << "No field should be left empty" << std::endl;
		return ;
	}
	Contact		new_contact(index + 1, first_name, last_name, nickname,
					phone_number, darkest_secret);
	book[index] = new_contact;
	if (index < 7)
		index += 1;
	else
		index = 0;
	if (count < 8)
		count += 1;
}

void	PhoneBook::search()
{
	std::string	input;
	int		i = 0;

	if (!count)
		return ;
	while (i < count)
	{
		book[i].display_info();
		i++;
	}
	input = get_input("Enter the index of the entry to display");
	if (std::cin.eof() == true)
		return ;
	if (is_valid_index(input, count) == false)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	book[input.at(0) - '0' - 1].display_full_info();
}
