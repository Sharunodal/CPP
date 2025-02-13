/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:10:00 by arissane          #+#    #+#             */
/*   Updated: 2025/02/06 13:15:06 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

std::string	get_input(std::string prompt);

class	PhoneBook
{
	private:
		Contact	book[8];
		int	index;
		int	count;
	public:
		PhoneBook();
		void	add();
		void	search();
};
#endif
