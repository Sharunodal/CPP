/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:44:20 by arissane          #+#    #+#             */
/*   Updated: 2025/04/14 09:49:19 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter( T* array, size_t length, F function )
{
	if ( !array )
	{
		std::cerr << "Error: empty array" << std::endl;
		return ;
	}
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

#endif
