/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:46:42 by arissane          #+#    #+#             */
/*   Updated: 2025/02/24 14:15:02 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl = Harl();

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
