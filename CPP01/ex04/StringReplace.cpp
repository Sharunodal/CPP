/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:31:10 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 11:18:25 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

StringReplace::StringReplace(const std::string& str1, const std::string& str2) : s1(str1), s2(str2)
{
}

StringReplace::~StringReplace()
{
}

std::string	StringReplace::replaceString(std::string& line) const
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

bool	StringReplace::processFile(const std::string& infile, const std::string outfile) const
{
	std::ifstream	in;
	std::ofstream	out;
	std::string	line;
	std::string	newLine;

	in.open(infile.c_str());
	if (!in)
	{
		std::cout << "Opening infile failed" << std::endl;
		return false;
	}
	out.open(outfile.c_str());
	if (!out)
	{
		std::cout << "Opening outfile failed" << std::endl;
		in.close();
		return false;
	}
	while (std::getline(in, line))
	{
		newLine = replaceString(line);
		out << newLine << '\n';
	}
	in.close();
	out.close();
	return true;
}
