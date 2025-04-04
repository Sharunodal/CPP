/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:37:03 by arissane          #+#    #+#             */
/*   Updated: 2025/04/03 11:51:15 by arissane         ###   ########.fr       */
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

bool    isCharacter(const std::string& str)
{
    if (str.length() == 1 && std::isalpha(str[0]))
    {
        return true;
    }
    return false;
}

bool    isInteger(const std::string& str)
{
    if (str.empty() == true)
    {
        return false;
    }
    size_t  i = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        i = 1;
    }
    for (; i < str.size(); i++)
    {
        if (std::isdigit(str[i]) == false)
        {
            return false;
        }
    }
    return true;
}

void    convertChar(const std::string& str)
{
    std::cout << "char: " << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void    convertInt(const std::string& str)
{
    try
    {
        std::cout << "char: ";
        int number = std::stoi(str);
        if (number >= 0 && number <= 255)
        {
            char c = number;
            if (std::isprint(c))
            {
                std::cout << "'" << c << "'" << std::endl;
            }
            else
            {
              std::cout << "Non displayable" << std::endl;
            }
        }
        else
        {
            std::cout << "impossible" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "impossible" << std::endl;
    }
    try
    {
        std::cout << "int: ";
        int number = std::stoi(str);
        std::cout << number << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "impossible" << std::endl;
    }
    std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void	ScalarConverter::convert(const std::string& str)
{
    if (str.empty())
    {
        std::cout << "no input found" << std::endl;
        return ;
    }
    if (isCharacter(str) == true)
    {
        convertChar(str);
    }
    else if (isInteger(str) == true)
    {
        convertInt(str);
    }
    else
    {
        std::cout << "error" << std::endl;
    }
}