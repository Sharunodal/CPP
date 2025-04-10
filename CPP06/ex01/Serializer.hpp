/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:08:19 by arissane          #+#    #+#             */
/*   Updated: 2025/04/10 11:12:36 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>
# include <cstdint>

class Serializer {
	private:
		Serializer() = delete;
		Serializer(Serializer& source) = delete;
		~Serializer() = delete;

		Serializer&	operator = (const Serializer& source) = delete;
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
