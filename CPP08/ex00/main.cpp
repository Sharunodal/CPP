/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:56:28 by arissane          #+#    #+#             */
/*   Updated: 2025/04/16 10:04:28 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>
#include <iostream>

int	main()
{
	try
	{
		std::vector<int> vec = {32, 77, 42, 2, 179};
		easyfind(vec, 42);
		easyfind(vec, 77);
		std::array<int, 5> arr = {22, 54, 21, 7, 1};
		easyfind(arr, 7);
		std::vector<int> empty = {};
		easyfind(empty, 55);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
