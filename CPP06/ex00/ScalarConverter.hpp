/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:11 by arissane          #+#    #+#             */
/*   Updated: 2025/04/10 12:32:12 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cmath>
# include <cfloat>
# include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& source);
		~ScalarConverter();
		ScalarConverter&	operator = (const ScalarConverter& source);
	public:
		static void	convert(const std::string& str);
		static void	convertChar(const char& character, const double& value);
		static void	convertInt(const int& integer, const double& value);
		static void	convertFloat(const float& fl, const double& value);
		static void	convertDouble(const double& value);
		static int	checkType(const std::string& str, const double value);
		static void	handleSpecial(const std::string& str);
};

#endif
