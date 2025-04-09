/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:11 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 11:40:50 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cmath>
# include <cfloat>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& source);
		~ScalarConverter();

		ScalarConverter&	operator = (const ScalarConverter& source);
	public:
		static void	convert(const std::string& str);
};

#endif
