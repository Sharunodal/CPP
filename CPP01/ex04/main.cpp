/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:26 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 11:08:08 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

int	main(int argc, char **argv)
{
	std::string	new_line;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" <<std::endl;
		return 1;
	}
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "The strings shouldn't be empty" << std::endl;
		return 1;
	}
	StringReplace	Replace(s1, s2);
	std::string	infile = argv[1];
	std::string	outfile = infile + ".replace";
	if (Replace.processFile(infile, outfile) == false)
		return 1;
	std::cout << infile << " copied to " << outfile << " with every occurrence of \"" << s1 << "\" replaced with \"" << s2 << "\"" << std::endl;
	return 0;
}
