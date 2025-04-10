/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:01 by arissane          #+#    #+#             */
/*   Updated: 2025/04/10 13:05:21 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		data;
	uintptr_t	raw = 0;

	data.index = 1;
	data.character = 'f';

	std::cout << "raw: " << raw << std::endl;
	std::cout << "index: " << data.index << std::endl;
	std::cout << "character: " << data.character << std::endl;

	raw = Serializer::serialize(&data);

	std::cout << "Serialized: " << raw << std::endl;

	Data *newData = Serializer::deserialize(raw);

	std::cout << "index: " << data.index << std::endl;
	std::cout << "character: " << data.character << std::endl;

	if (&data == newData)
	{
		std::cout << "equal" << std::endl;
	}
	else
	{
		std::cout << "inequal" << std::endl;
	}
}
