/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:39:17 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 13:47:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <iomanip>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& source);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		~BitcoinExchange();

		void	loadDatabase();
		void	exchange(char* inputFile);
		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& valueString, float& value);
		std::string	findClosestDate(const std::string& date);
};

#endif
