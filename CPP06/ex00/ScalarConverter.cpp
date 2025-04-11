/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:03 by arissane          #+#    #+#             */
/*   Updated: 2025/04/11 11:30:45 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter& source)
{
	(void)source;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&    ScalarConverter::operator = (const ScalarConverter& source)
{
	(void)source;
	return *this;
}

void    ScalarConverter::convertChar(const char& character, const double& value)
{
	if (value < CHAR_MIN || value > CHAR_MAX)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (value < 32 || value > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: " << "'" << character << "'" << std::endl;
	}
}

void    ScalarConverter::convertInt(const int& integer, const double& value)
{
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << integer << std::endl;
	}
}

void    ScalarConverter::convertFloat(const float& fl, const double& value)
{
	if (value < -FLT_MAX || value > FLT_MAX)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << fl << "f" << std::endl;
	}
}

void    ScalarConverter::convertDouble(const double& value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

int    ScalarConverter::checkType(const std::string& str, const double value)
{
	if (str.size() == 1)
	{
		return 1;
	}
	int dots = 0;
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			dots++;
		}
		if (dots > 1 || std::isdigit(str[i]) == false)
		{
			if (dots == 1 && str[i] == '.')
			{
				continue ;
			}
			if (i == str.size() - 1 && str[i] == 'f')
			{
				return 3;
			}
			throw std::runtime_error("impossible");
		}
	}
	if (dots == 0 && value >= INT_MIN && value <= INT_MAX)
	{
		return 2;
	}
	return 4;
}

void    ScalarConverter::handleSpecial(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	enum specialCase {POSITIVE_INFINITY, NEGATIVE_INFINITY, NAN_CASE, NONE};
	specialCase special = NONE;
	if (str == "+inf" || str == "+inff")
	{
		special = POSITIVE_INFINITY;
	}
	else if (str == "-inf" || str == "-inff")
	{
		special = NEGATIVE_INFINITY;
	}
	else if (str == "nan" || str == "nanf")
	{
		special = NAN_CASE;
	}
	switch (special)
	{
		case POSITIVE_INFINITY:
			std::cout << "float: +inff" << std::endl;
			break;
		case NEGATIVE_INFINITY:
			std::cout << "float: -inff" << std::endl;
			break;
		case NAN_CASE:
			std::cout << "float: nanf" << std::endl;
			break;
		default:
			std::cout << "float: impossible" << std::endl;
	}
	switch (special)
	{
		case POSITIVE_INFINITY:
			std::cout << "double: +inf" << std::endl;
			break;
		case NEGATIVE_INFINITY:
			std::cout << "double: -inf" << std::endl;
			break;
		case NAN_CASE:
			std::cout << "double: nan" << std::endl;
			break;
		default:
			std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
		return ;
	}
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf")
	{
		handleSpecial(str);
		return ;
	}
	try
	{
		double value = 0;
		if (str.size() == 1 && std::isdigit(str[0]) == false)
		{
			value = static_cast<double>(str[0]);
		}
		else
		{
			value = std::stod(str);
			if (errno == ERANGE)
			{
				throw std::out_of_range("Number out of range");
			}
		}
		int type = checkType(str, value);
		switch (type)
		{
			case 1:
				{
					char character = str[0];
					if (character >= '0' && character <= '9')
					{
						character -= 48;
					}
					convertChar(character, value);
					convertInt(static_cast<int>(character), value);
					convertFloat(static_cast<float>(character), value);
					convertDouble(value);
					break ;
				}
			case 2:
				{
					int integer = stoi(str);
					convertChar(static_cast<char>(integer), value);
					convertInt(integer, value);
					convertFloat(static_cast<float>(integer), value);
					convertDouble(value);
					break ;
				}
			case 3:
				{
					float fl = std::stof(str);
					convertChar(static_cast<char>(fl), value);
					convertInt(static_cast<int>(fl), value);
					convertFloat(fl, value);
					convertDouble(value);
					break ;
				}
			case 4:
				{
					convertChar(static_cast<char>(value), value);
					convertInt(static_cast<int>(value), value);
					convertFloat(static_cast<float>(value), value);
					convertDouble(value);
					break ;
				}
			default:
				throw std::invalid_argument("Unknown type");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
	}
}
