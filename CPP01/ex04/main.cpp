/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:26 by arissane          #+#    #+#             */
/*   Updated: 2025/02/24 10:35:55 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_string(std::string& line, std::string& s1, std::string& s2)
{
	std::string	result;
	size_t		found_at = 0;
	size_t		start_from = 0;
	size_t		copy_until = 0;

	while ((found_at = line.find(s1, start_from)) != std::string::npos)
	{
		copy_until = found_at - start_from;
		result.append(line, start_from, copy_until);
		result.append(s2);
		start_from = found_at + s1.length();
	}
	result.append(line, start_from, line.length());
	return result;
}

int	main(int argc, char **argv)
{
	std::string	new_line;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" <<std::endl;
		return 1;
	}
	std::string	s1 = argv[2];//replace this
	std::string	s2 = argv[3];//write this
	if (s1.empty() || s2.empty())
	{
		std::cout << "The strings shouldn't be empty" << std::endl;
		return 1;
	}

	std::ifstream	infile;
	std::ofstream	outfile;
	infile.open(argv[1]);
	if (!infile)
	{
		std::cout << "Opening infile failed" << std::endl;
		return 1;
	}
	std::string	outfilename = argv[1] + std::string(".replace");
	outfile.open(outfilename.c_str());
	if (!outfile)
	{
		std::cout << "Opening outfile failed" << std::endl;
		return 1;
	}
	std::string	line;
	while (std::getline(infile, line))
	{
		std::cout << "writing \"" << line << "\"" << std::endl;
		new_line = replace_string(line, s1, s2);
		outfile << new_line << '\n';
	}
	infile.close();
	outfile.close();
	return 0;
}
