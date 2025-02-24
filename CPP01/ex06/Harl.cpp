/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:59:08 by arissane          #+#    #+#             */
/*   Updated: 2025/02/24 14:20:21 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	(Harl::*Harl::functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

std::string	Harl::levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	int	i = 0;

	while (i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break ;
		case 1:
			info();
			warning();
			error();
			break ;
		case 2:
			warning();
			error();
			break ;
		case 3:
			error();
			break ;
		default:
			std::cout << "Highest level exceeded" << std::endl;
	}
}
