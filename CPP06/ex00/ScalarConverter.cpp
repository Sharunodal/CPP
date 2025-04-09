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

void    convertChar(const char& character, const double& value)
{
    if (value < CHAR_MIN || value > CHAR_MAX || value != std::floor(value))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (value < 33 || value > 126)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: " << "'" << character << "'" << std::endl;
    }
}

void    convertInt(const int& integer, const double& value)
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

void    convertFloat(const float& fl, const double& value)
{
    if (value < -FLT_MAX || value > FLT_MAX)
    {
        std::cout << "float: impossible" << std::endl;
        return ;
    }
    if (fl == std::floor(fl))
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << fl << "f" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << fl << "f" << std::endl;
    }
}

void    convertDouble(const double& value)
{
    if (value == std::floor(value))
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

int    checkType(const std::string& str, const double value)
{
    if (str.size() == 1)
    {
        return 1;
    }
    int dots = 0;
    for (size_t i = 0; i < str.size(); i++)
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

void    handleSpecial(const std::string& str, double* value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "+inff")
    {
        *value = +INFINITY;
        std::cout << "float: +inf" << std::endl;
    }
    else if (str == "-inff")
    {
        *value = -INFINITY;
        std::cout << "float: -inf" << std::endl;
    }
    else if (str == "nanf")
    {
        *value = NAN;
        std::cout << "float: nanf" << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
    }
    if (str == "+inf" || str == "+inff")
    {
        *value = +INFINITY;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        *value = -INFINITY;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "nanf" || str == "nan")
    {
        *value = NAN;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "double: impossible" << std::endl;
    }
}

void	ScalarConverter::convert(const std::string& str)
{
    double value = 0;
    if (str.empty())
    {
        std::cout << "no input found" << std::endl;
        return ;
    }
    if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf")
    {
        handleSpecial(str, &value);
        return ;
    }
    try
    {
        if (str.size() == 1 && std::isdigit(str[0]) == false)
        {
            value = static_cast<double>(str[0]);
        }
        else
        {
            value = std::stod(str);
        }
        if (errno == ERANGE)
        {
            throw std::out_of_range("Number out of range");
        }
        int type = checkType(str, value);
        if (type == 1)
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
            return ;
        }
        if (type == 2)
        {
            int integer = stoi(str);
            convertChar(static_cast<char>(integer), value);
            convertInt(integer, value);
            convertFloat(static_cast<float>(integer), value);
            convertDouble(value);
            return ;
        }
        if (type == 3)
        {
            float fl = std::stof(str);
            convertChar(static_cast<char>(fl), value);
            convertInt(static_cast<int>(fl), value);
            convertFloat(fl, value);
            convertDouble(value);
            return ;
        }
        if (type == 4)
        {
            convertChar(static_cast<char>(value), value);
            convertInt(static_cast<int>(value), value);
            convertFloat(static_cast<float>(value), value);
            convertDouble(value);
            return ;
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