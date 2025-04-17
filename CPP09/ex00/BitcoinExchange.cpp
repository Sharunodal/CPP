/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:39:53 by arissane          #+#    #+#             */
/*   Updated: 2025/04/17 13:53:40 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	_data = source._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	if (this != &source)
	{
		_data = source._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
