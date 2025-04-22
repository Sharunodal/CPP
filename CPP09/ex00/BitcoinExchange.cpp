/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:39:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/22 13:07:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	_data = source._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	if (this != &source)
	{
		_data = source._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase()
{
	std::ifstream db("data.csv");
	if (db.is_open() == false)
	{
		throw std::runtime_error("Error: could not open database file");
	}
	std::string	line;
	std::getline(db, line);
	if (line != "date,exchange_rate")
	{
		throw std::runtime_error("Error: invalid csv file");
	}
	while (std::getline(db, line))
	{
		size_t	comma = line.find(',');
		if (comma == std::string::npos)
		{
			continue;
		}
		std::string date = line.substr(0, comma);
		std::string	rateString = line.substr(comma + 1);
		float	rate;
		std::istringstream inputStream(rateString);
		if (!(inputStream >> rate))
		{
			continue;
		}
		_data[date] = rate;
	}
	db.close();
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
	{
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	std::istringstream inputstream(date);
	int	year, month, day;
	char	dash1, dash2;

	if (!(inputstream >> year >> dash1 >> month >> dash2 >> day))//extract values from the input stream by type int >> char >> int..
	{
		return false;
	}
	if (dash1 != '-' || dash2 != '-')
	{
		return false;
	}
	if (year < 0 || month < 1 || month > 12 || day < 1)
	{
		return false;
	}
	if (month == 2)
	{
		bool	leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (leapYear ? 29 : 28))
		{
			return false;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			return false;
		}
	}
	else if (day > 31)
	{
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& valueString, float& value)
{
	if (valueString.empty() == true)
	{
		return false;
	}
	size_t	start = 0;
	if (valueString[0] == '-')
	{
		start = 1;
	}
	if (valueString.find_first_not_of("0123456789.", start) != std::string::npos)
	{
		return false;
	}
	if (std::count(valueString.begin(), valueString.end(), '.') > 1)
	{
		return false;
	}
	char *end;
	value = std::strtof(valueString.c_str(), &end);
	if (*end != '\0')
	{
		return false;
	}
	if (value < 0 || value > 1000)
	{
		return false;
	}
	return true;
}

std::string	BitcoinExchange::findClosestDate(const std::string& date)
{
	if (_data.empty())
	{
		return "";
	}
	std::map<std::string, float>::iterator iter = _data.lower_bound(date);
	if (iter == _data.begin())
	{
		return iter->first;
	}
	if (iter == _data.end() || iter->first > date)
	{
		--iter;
	}
	return iter->first;
}

void	BitcoinExchange::exchange(char* inputFile)
{
	std::ifstream	file(inputFile);
	if (file.is_open() == false)
	{
		throw std::runtime_error("Error: could not open file");
	}

	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
	{
		throw std::runtime_error("Error: invalid input file.");
	}
	while (std::getline(file, line))
	{
		size_t	pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, pipe);
		std::string	valueString = line.substr(pipe + 1);
		date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueString.erase(0, valueString.find_first_not_of(" \t"));
        valueString.erase(valueString.find_last_not_of(" \t") + 1);
		if (date.empty() || valueString.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (isValidDate(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		float	value;
		if (isValidValue(valueString, value) == false)
		{
			float	testValue = 0;
			char*	end;
			testValue = std::strtof(valueString.c_str(), &end);
			if (*end != '\0')
			{
				std::cout << "Error: bad input => " << valueString << std::endl;
			}
			if (testValue < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
			}
			else if (testValue > 1000)
			{
				std::cout << "Error: too large a number" << std::endl;
			}
			else
			{
				std::cout << "Error: bad input => " << valueString << std::endl;
			}
			continue;
		}

		std::string	closestDate = findClosestDate(date);
		if (closestDate.empty() == true)
		{
			std::cout << "Error: no data available for " << date << std::endl;
			continue;
		}

		float	rate = _data[closestDate];
		float	result = value * rate;
		std::cout << date << " => " << value << " = " << std::setprecision(2) << result << std::endl;
	}
	file.close();
}
