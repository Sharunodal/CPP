/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:48:23 by arissane          #+#    #+#             */
/*   Updated: 2025/04/16 10:09:11 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T> int easyfind(T container, int integer)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), integer);
	if (iter == container.end())
	{
		throw std::runtime_error("Value not found in the container");
	}
	else
	{
		std::cout << "Found " << *iter << std::endl;
		return *iter;
	}
};

#endif
