/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:01 by arissane          #+#    #+#             */
/*   Updated: 2025/04/11 11:45:59 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		data;
	uintptr_t	raw = 0;

	data.index = 1;
	data.character = 'f';

	std::cout << "uintptr_t raw: " << raw << std::endl;
	std::cout << "data.index: " << data.index << std::endl;
	std::cout << "data.character: " << data.character << std::endl;

	std::cout << "\n&data: " << &data << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Data serialized (memory address converted to a numeric value)\nraw = serialize(&data): " << raw << std::endl;

	Data *newData = Serializer::deserialize(raw);
	std::cout << "newData pointer created with deserialized raw value\nnewData: " << newData << std::endl;

	std::cout << "\ndata.index: " << data.index << std::endl;
	std::cout << "data.character: " << data.character << std::endl;
	std::cout << "newData->index: " << newData->index << std::endl;
	std::cout << "newData->character: " << newData->character << std::endl;
}
