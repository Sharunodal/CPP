/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:31:03 by arissane          #+#    #+#             */
/*   Updated: 2025/02/26 10:50:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACE_HPP
#define STRINGREPLACE_HPP

# include <iostream>
# include <fstream>

class	StringReplace
{
	private:
		const std::string	s1;
		const std::string	s2;
	public:
		StringReplace(const std::string& str1, const std::string& str2);
		~StringReplace();
		std::string	replaceString(std::string& line) const;
		bool		processFile(const std::string& infile,
					const std::string outfile) const;
};

#endif
