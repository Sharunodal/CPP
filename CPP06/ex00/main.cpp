/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:52:22 by arissane          #+#    #+#             */
/*   Updated: 2025/04/11 11:32:08 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	automaticTests()
{
	std::cout << "./convert 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "./convert nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "./convert 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << "\n./convert 5" << std::endl;
	ScalarConverter::convert("5");
	std::cout << "\n./convert 105" << std::endl;
	ScalarConverter::convert("105");
	std::cout << "\n./convert a" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "\n./convert aa" << std::endl;
	ScalarConverter::convert("aa");
	std::cout << "\n./convert \"\"" << std::endl;
	ScalarConverter::convert("");
	std::cout << "\n./convert -A" << std::endl;
	ScalarConverter::convert("-A");
	std::cout << "\n./convert -2" << std::endl;
	ScalarConverter::convert("-2");
	std::cout << "\n./convert +inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "\n./convert +inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "\n./convert -inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "\n./convert -inff" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "\n./convert nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "\n./convert 2147483647" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "\n./convert 2147483648" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << "\n./convert -2147483648" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "\n./convert -2147483649" << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout << "\n./convert 340282346638528859811704183484516925440" << std::endl;
	ScalarConverter::convert("340282346638528859811704183484516925440");
	std::cout << "\n./convert 340282346738528859811704183484516925441" << std::endl;
	ScalarConverter::convert("340282346738528859811704183484516925441");
	std::cout << "\n./convert 0.000000000000000000000000000000000117549435" << std::endl;
	ScalarConverter::convert("0.000000000000000000000000000000000117549435");
	std::cout << "\n./convert 180000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << std::endl;
	ScalarConverter::convert("180000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string arg = argv[1];
	if (arg == "test")
	{
		automaticTests();
	}
	else
	{
		ScalarConverter::convert(argv[1]);
	}
	return 0;
}
